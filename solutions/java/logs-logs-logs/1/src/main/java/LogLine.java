public class LogLine {
    String logLevel_ = "";
    String logLine_ = "";
    public LogLine(String logLine) {
        logLine_ = logLine;
        logLevel_ = logLine.substring(logLine.indexOf("[") + 1, logLine.indexOf("]"));

    }

    public LogLevel getLogLevel() {
        LogLevel logLevel = LogLevel.UNKNOWN;
        switch(logLevel_){
            case "TRC":
                logLevel = LogLevel.TRACE;
                break;
            case "DBG":
                logLevel = LogLevel.DEBUG;
                break;
            case "INF":
                logLevel = LogLevel.INFO;
                break;
            case "WRN":
                logLevel = LogLevel.WARNING;
                break;
            case "ERR":
                logLevel = LogLevel.ERROR;
                break;
            case "FTL":
                logLevel = LogLevel.FATAL;
                break;
        }
        return logLevel;
    }

    public String getOutputForShortLog() {
        String shortLog = "";
        switch(logLevel_){
            case "TRC":
                shortLog += 1;
                break;
            case "DBG":
                shortLog += 2;
                break;
            case "INF":
                shortLog += 4;
                break;
            case "WRN":
                shortLog += 5;
                break;
            case "ERR":
                shortLog += 6;
                break;
            case "FTL":
                shortLog += 42;
                break;
            default:
                shortLog += 0;
                break;
        }
        return shortLog + ":" + logLine_.substring(logLine_.indexOf(":") + 2);
    }
}
