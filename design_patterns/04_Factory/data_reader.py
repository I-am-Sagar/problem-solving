import csv
import json
import xml.etree.ElementTree as ET
from abc import ABC, abstractmethod
import os
import sys

# Abstract class for DataReader
class DataReader(ABC):
    @abstractmethod
    def read_data(self, file_path):
        pass

# Concrete implementations of DataReader
class CSVDataReader(DataReader):
    def read_data(self, file_path):
        data = []
        with open(file_path, 'r') as file:
            csv_reader = csv.reader(file)
            for row in csv_reader:
                data.append(row)
        return data

class JSONDataReader(DataReader):
    def read_data(self, file_path):
        with open(file_path, 'r') as file:
            data = json.load(file)
        return data

class XMLDataReader(DataReader):
    def read_data(self, file_path):
        tree = ET.parse(file_path)
        root = tree.getroot()
        data = []
        for element in root:
            element_data = {}
            for child in element:
                element_data[child.tag] = child.text
            data.append(element_data)
        return data

# Factory class for creating data readers
class DataReaderFactory:
    @staticmethod
    def create_data_reader(file_path):
        file_extension = os.path.splitext(file_path)[1].lower()
        if file_extension == ".csv":
            return CSVDataReader()
        elif file_extension == ".json":
            return JSONDataReader()
        elif file_extension == ".xml":
            return XMLDataReader()
        else:
            raise ValueError("Unsupported file type")

# Client code
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <file_path>")
        sys.exit(1)

    file_path = sys.argv[1]
    
    data_reader = DataReaderFactory.create_data_reader(file_path)
    data = data_reader.read_data(file_path)
    print("Data read from", file_path, ":", data)