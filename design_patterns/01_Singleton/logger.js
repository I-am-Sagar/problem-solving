const fs = require('fs');
const path = require('path');

class Logger {
    constructor() {
        if (Logger.instance) {
            return Logger.instance;
        }
        
        this._logFile = path.join(__dirname, 'app.log');
        Logger.instance = this;
    }

    log(message) {
        fs.appendFileSync(this._logFile, `${message}\n`);
    }
}

// Example usage
const logger1 = new Logger();
const logger2 = new Logger();

logger1.log("Logging from logger1");
logger2.log("Logging from logger2");

console.log(`Logger1 and Logger2 are the same instance: ${logger1 === logger2}`);
