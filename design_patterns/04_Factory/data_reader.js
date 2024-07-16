const fs = require('fs');
const path = require('path');

// Abstract class for DataReader
class DataReader {
    readData(file_path) {}
}

// Concrete implementations of DataReader
class CSVDataReader extends DataReader {
    readData(file_path) {
        const data = fs.readFileSync(file_path, 'utf8').split('\n').map(row => row.split(','));
        return data;
    }
}

class JSONDataReader extends DataReader {
    readData(file_path) {
        const data = JSON.parse(fs.readFileSync(file_path, 'utf8'));
        return data;
    }
}

class XMLDataReader extends DataReader {
    readData(file_path) {
        const xmlContent = fs.readFileSync(file_path, 'utf8');
        const data = this.parseXML(xmlContent);
        return data;
    }

    parseXML(xmlContent) {
        const parser = new Parser();
        const data = {};
        parser.parseString(xmlContent, (err, result) => {
            if (err) {
                console.error(err);
                return;
            }
            data.root = result;
        });
        return data;
    }
}

// Factory class for creating data readers
class DataReaderFactory {
    static createDataReader(file_path) {
        const file_extension = path.extname(file_path).toLowerCase();
        if (file_extension === ".csv") {
            return new CSVDataReader();
        } else if (file_extension === ".json") {
            return new JSONDataReader();
        } else if (file_extension === ".xml") {
            return new XMLDataReader();
        } else {
            throw new Error("Unsupported file type");
        }
    }
}

// Client code
if (process.argv.length !== 3) {
    console.log("Usage: node script.js <file_path>");
    process.exit(1);
}

const file_path = process.argv[2];

const dataReader = DataReaderFactory.createDataReader(file_path);
const data = dataReader.readData(file_path);
console.log("Data read from", file_path, ":", data);
