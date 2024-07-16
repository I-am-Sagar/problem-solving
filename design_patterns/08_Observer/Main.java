import java.util.ArrayList;
import java.util.List;

// Subject (Observable)
interface Subject {
    void registerObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
}

// Concrete Subject
class WeatherStation implements Subject {
    private Double temperature;
    private List<Observer> observers;

    public WeatherStation() {
        this.observers = new ArrayList<>();
    }

    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(temperature);
        }
    }

    public void setTemperature(Double temperature) {
        System.out.println("Setting temperature to: " + temperature);
        this.temperature = temperature;
        notifyObservers();
    }
}

// Observer
interface Observer {
    void update(Double temperature);
}

// Concrete Observer
class Display implements Observer {
    private String name;

    public Display(String name) {
        this.name = name;
    }

    public void update(Double temperature) {
        System.out.println(name + " received temperature update: " + temperature);
    }
}

// Usage example
public class Main {
    public static void main(String[] args) {
        WeatherStation weatherStation = new WeatherStation();

        Observer observer1 = new Display("Observer 1");
        Observer observer2 = new Display("Observer 2");

        weatherStation.registerObserver(observer1);
        weatherStation.registerObserver(observer2);

        weatherStation.setTemperature(25.5);
        weatherStation.setTemperature(30.0);

        weatherStation.removeObserver(observer1);

        weatherStation.setTemperature(27.8);
    }
}
