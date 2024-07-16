# Define the appliance classes
class Light:
    def on(self):
        print("Light is on")

    def off(self):
        print("Light is off")

class Television:
    def on(self):
        print("Television is on")

    def off(self):
        print("Television is off")

class AirConditioner:
    def on(self):
        print("Air Conditioner is on")

    def off(self):
        print("Air Conditioner is off")

# Define the HomeFacade class
class HomeFacade:
    def __init__(self):
        self.light = Light()
        self.tv = Television()
        self.ac = AirConditioner()

    def evening_mode(self):
        print("Setting evening mode...")
        self.light.on()
        self.tv.on()
        self.ac.on()

    def morning_mode(self):
        print("Setting morning mode...")
        self.light.off()
        self.tv.off()
        self.ac.off()

# Using the HomeFacade to control appliances
if __name__ == "__main__":
    home = HomeFacade()

    # Activating evening mode
    home.evening_mode()
    print()
    # Activating morning mode
    home.morning_mode()
