/// <reference path="./global.d.ts" />
// @ts-check
//
// The lines above enable type checking for this file. Various IDEs interpret
// the @ts-check and reference directives. Together, they give you helpful
// autocompletion when implementing this exercise. You don't need to understand
// them in order to use it.
//
// In your own projects, files, and code, you can play with @ts-check as well.

export class TranslationService {
  /**
   * Creates a new service
   * @param {ExternalApi} api the original api
   */
  constructor(api) {
    this.api = api;
  }

  /**
   * Attempts to retrieve the translation for the given text.
   *
   * - Returns whichever translation can be retrieved, regardless the quality
   * - Forwards any error from the translation api
   *
   * @param {string} text
   * @returns {Promise<string>}
   */
  free(text) {
    return this.api.fetch(text).then((result) => result.translation);
  }

  /**
   * Batch translates the given texts using the free service.
   *
   * - Resolves all the translations (in the same order), if they all succeed
   * - Rejects with the first error that is encountered
   * - Rejects with a BatchIsEmpty error if no texts are given
   *
   * @param {string[]} texts
   * @returns {Promise<string[]>}
   */
  batch(texts) {
    // 1. Check if texts is empty
    if (texts.length === 0) {
      return Promise.reject(new BatchIsEmpty());
    }
  
    // 2. Map the strings to 'free' promises
    const promises = texts.map((text) => this.free(text));
  
    // 3. Return the Promise.all of that array
    return Promise.all(promises);
  }

  /**
   * Requests the service for some text to be translated.
   *
   * Note: the request service is flaky, and it may take up to three times for
   *       it to accept the request.
   *
   * @param {string} text
   * @returns {Promise<void>}
   */
  request(text) {
    return new Promise((resolve, reject) => {
    const makeRequest = (attempt = 1) => {
      this.api.request(text, (error) => {
        if (!error) {
          return resolve(); // Success! Resolve with undefined
        }
        
        // If it failed and we have attempts left (max 3), try again
        if (attempt < 3) {
          makeRequest(attempt + 1);
        } else {
          // No more retries left, fail with the last error
          reject(error);
        }
      });
    };

    makeRequest();
  });
  }

  /**
   * Retrieves the translation for the given text
   *
   * - Rejects with an error if the quality can not be met
   * - Requests a translation if the translation is not available, then retries
   *
   * @param {string} text
   * @param {number} minimumQuality
   * @returns {Promise<string>}
   */
  premium(text, minimumQuality) {
    return this.api.fetch(text)
    .then((result) => {
      // 1. Check quality of the initial fetch
      if (result.quality < minimumQuality) {
        throw new QualityThresholdNotMet(text);
      }
      return result.translation;
    })
    .catch((error) => {
      // 2. If fetch failed because it's not in storage
      if (error.constructor.name === 'NotAvailable') {
        return this.request(text)
          .then(() => this.api.fetch(text)) // 3. Fetch again after requesting
          .then((newResult) => {
            // 4. Final quality check
            if (newResult.quality < minimumQuality) {
              throw new QualityThresholdNotMet(text);
            }
            return newResult.translation;
          });
      }
      // 5. Forward any other errors (like Untranslatable)
      throw error;
    });
  }
}

/**
 * This error is used to indicate a translation was found, but its quality does
 * not meet a certain threshold. Do not change the name of this error.
 */
export class QualityThresholdNotMet extends Error {
  /**
   * @param {string} text
   */
  constructor(text) {
    super(
      `
The translation of ${text} does not meet the requested quality threshold.
    `.trim(),
    );

    this.text = text;
  }
}

/**
 * This error is used to indicate the batch service was called without any
 * texts to translate (it was empty). Do not change the name of this error.
 */
export class BatchIsEmpty extends Error {
  constructor() {
    super(
      `
Requested a batch translation, but there are no texts in the batch.
    `.trim(),
    );
  }
}
