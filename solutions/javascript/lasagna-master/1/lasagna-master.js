/// <reference path="./global.d.ts" />
// @ts-check

/**
 * Implement the functions needed to solve the exercise here.
 * Do not forget to export them so they are available for the
 * tests. Here an example of the syntax as reminder:
 *
 * export function yourFunction(...) {
 *   ...
 * }
 */

export function cookingStatus(remainingTime){
  if (remainingTime === 0){
    return 'Lasagna is done.';
  }
  else if (remainingTime == undefined){
    return 'You forgot to set the timer.';
  }
  else{
    return 'Not done, please wait.';
  }
}

export function preparationTime(layers, avgPrepTimePerLayer = 2){
  return layers.length * avgPrepTimePerLayer;
}

export function quantities(layers){
  let noodleQuantity = 0;
  let sauceQuantity = 0;

  for (let layer of layers) {
    if (layer == 'noodles'){
      noodleQuantity += 50;
    }
    else if (layer == 'sauce'){
      sauceQuantity += 0.2;
    }
  }

  return {'noodles': noodleQuantity, 'sauce': sauceQuantity};
}

export function addSecretIngredient(friendIngredients, myIngredients){
  myIngredients.push(friendIngredients[friendIngredients.length - 1]);
}

export function scaleRecipe(recipe, numPortions){
  const scaledRecipe = {};
  let num = numPortions/2;

  for (let key in recipe) {
    scaledRecipe[key] = recipe[key] * num;
  }

  return scaledRecipe;
}