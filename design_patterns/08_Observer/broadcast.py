from abc import ABC, abstractmethod

# Abstract Subject
class Subject(ABC):
    @abstractmethod
    def register_observer(self, observer):
        pass
    
    @abstractmethod
    def remove_observer(self, observer):
        pass
    
    @abstractmethod
    def notify_observers(self):
        pass

# Concrete Subject
class WeatherStation(Subject):
    def __init__(self):
        self._temperature = None
        self._observers = []

    def register_observer(self, observer):
        self._observers.append(observer)

    def remove_observer(self, observer):
        self._observers.remove(observer)

    def notify_observers(self):
        for observer in self._observers:
            observer.update(self._temperature)

    def set_temperature(self, temperature):
        print("Setting temperature to:", temperature)
        self._temperature = temperature
        self.notify_observers()

# Abstract Observer
class Observer(ABC):
    @abstractmethod
    def update(self, temperature):
        pass

# Concrete Observer
class Display(Observer):
    def __init__(self, name):
        self._name = name

    def update(self, temperature):
        print(f"{self._name} received temperature update: {temperature}")

# Usage example
if __name__ == "__main__":
    weather_station = WeatherStation()

    observer1 = Display("Observer 1")
    observer2 = Display("Observer 2")

    weather_station.register_observer(observer1)
    weather_station.register_observer(observer2)

    weather_station.set_temperature(25.5)
    weather_station.set_temperature(30.0)

    weather_station.remove_observer(observer1)

    weather_station.set_temperature(27.8)
