// Subject (Observable)

// Libraries = Redux? Sveltestore? 
class WeatherStation {
    constructor() {
        this.temperature = null; // Variables (states) are dynamically taken care of, each state => observers
        this.observers = [];
    }

    registerObserver(observer) {
        this.observers.push(observer);
    }

    removeObserver(observer) {
        const index = this.observers.indexOf(observer);
        if (index !== -1) {
            this.observers.splice(index, 1);
        }
    }

    notifyObservers() {
        this.observers.forEach(observer => observer.update(this.temperature));
    }

    setTemperature(temperature) {
        console.log(`Setting temperature to: ${temperature}`);
        this.temperature = temperature;
        this.notifyObservers();
    }
}

// Observer
class Display {
    constructor(name) {
        this.name = name;
        // temperature
    }

    update(temperature) {
        console.log(`${this.name} received temperature update: ${temperature}`);
        // this.temperature = temperature
        // Whatever you want to trigger, when value change happens.
    }
}

// Usage example
const weatherStation = new WeatherStation();

const observer1 = new Display("Observer 1");
const observer2 = new Display("Observer 2");

weatherStation.registerObserver(observer1);
weatherStation.registerObserver(observer2);

weatherStation.setTemperature(25.5);
weatherStation.setTemperature(30.0);

weatherStation.removeObserver(observer1);

weatherStation.setTemperature(27.8);
