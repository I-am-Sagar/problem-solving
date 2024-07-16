// Define the appliance classes
class Light {
  on() {
    console.log('Light is on');
  }

  off() {
    console.log('Light is off');
  }
}

class Television {
  on() {
    console.log('Television is on');
  }

  off() {
    console.log('Television is off');
  }
}

class AirConditioner {
  on() {
    console.log('Air Conditioner is on');
  }

  off() {
    console.log('Air Conditioner is off');
  }
}

// Define the HomeFacade class
class HomeFacade {
  constructor() {
    this.light = new Light();
    this.tv = new Television();
    this.ac = new AirConditioner();
  }

  eveningMode() {
    console.log('Setting evening mode...');
    this.light.on();
    this.tv.on();
    this.ac.on();
  }

  morningMode() {
    console.log('Setting morning mode...');
    this.light.off();
    this.tv.off();
    this.ac.off();
  }
}

// Using the HomeFacade to control appliances
const home = new HomeFacade();

// Activating evening mode
home.eveningMode();
console.log();
// Activating morning mode
home.morningMode();
