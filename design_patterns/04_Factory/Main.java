import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

// Abstract class for DataReader
abstract class DataReader {
    abstract List<List<String>> readData(String filePath) throws IOException;
}

// Concrete implementations of DataReader
class CSVDataReader extends DataReader {
    @Override
    List<List<String>> readData(String filePath) throws IOException {
        List<List<String>> data = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                List<String> row = new ArrayList<>();
                String[] values = line.split(",");
                for (String value : values) {
                    row.add(value);
                }
                data.add(row);
            }
        }
        return data;
    }
}

class JSONDataReader extends DataReader {
    @Override
    List<List<String>> readData(String filePath) throws IOException {
        throw new UnsupportedOperationException("JSONDataReader not implemented");
    }
}

class XMLDataReader extends DataReader {
    @Override
    List<List<String>> readData(String filePath) throws IOException {
        throw new UnsupportedOperationException("XMLDataReader not implemented");
    }
}

// Factory class for creating data readers
class DataReaderFactory {
    static DataReader createDataReader(String filePath) {
        String fileExtension = filePath.substring(filePath.lastIndexOf('.')).toLowerCase();
        switch (fileExtension) {
            case ".csv":
                return new CSVDataReader();
            case ".json":
                return new JSONDataReader();
            case ".xml":
                return new XMLDataReader();
            default:
                throw new IllegalArgumentException("Unsupported file type");
        }
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Main <file_path>");
            System.exit(1);
        }

        String filePath = args[0];

        try {
            DataReader dataReader = DataReaderFactory.createDataReader(filePath);
            List<List<String>> data = dataReader.readData(filePath);
            System.out.println("Data read from " + filePath + ": " + data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
