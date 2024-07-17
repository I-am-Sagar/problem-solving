class TowerMediator:
    def __init__(self):
        self.runways = []
        self.airplanes = []

    def add_runway(self, runway):
        self.runways.append(runway)

    def add_airplane(self, airplane):
        self.airplanes.append(airplane)

    def request_to_land(self, airplane):
        for runway in self.runways:
            if runway.is_available:
                runway.land(airplane)
                return
        print(f"All runways are busy, {airplane.name} cannot land now.")

    def request_to_takeoff(self, airplane):
        for runway in self.runways:
            if runway.is_available:
                runway.takeoff(airplane)
                return
        print(f"All runways are busy, {airplane.name} cannot take off now.")

class Runway:
    def __init__(self, name):
        self.name = name
        self.is_available = True

    def land(self, airplane):
        if self.is_available:
            print(f"{airplane.name} is landing on {self.name}.")
            self.is_available = False
            airplane.land()
        else:
            print(f"{self.name} is currently occupied.")

    def takeoff(self, airplane):
        if self.is_available:
            print(f"{airplane.name} is taking off from {self.name}.")
            self.is_available = False
            airplane.takeoff()
        else:
            print(f"{self.name} is currently occupied.")

    def release(self):
        self.is_available = True
        print(f"{self.name} is now available.")

class Airplane:
    def __init__(self, name, mediator):
        self.name = name
        self.mediator = mediator
        self.is_flying = False

    def request_landing(self):
        print(f"{self.name} is requesting to land.")
        self.mediator.request_to_land(self)

    def request_takeoff(self):
        print(f"{self.name} is requesting to take off.")
        self.mediator.request_to_takeoff(self)

    def land(self):
        self.is_flying = False
        print(f"{self.name} has landed.")

    def takeoff(self):
        self.is_flying = True
        print(f"{self.name} has taken off.")

# Example usage
mediator = TowerMediator()

runway1 = Runway("Runway 1")
runway2 = Runway("Runway 2")

mediator.add_runway(runway1)
mediator.add_runway(runway2)

airplane1 = Airplane("Airplane 1", mediator)
airplane2 = Airplane("Airplane 2", mediator)

mediator.add_airplane(airplane1)
mediator.add_airplane(airplane2)

# Airplane 1 requests to land
airplane1.request_landing()

# Airplane 2 requests to land
airplane2.request_landing()

# Runway 1 is released and now available
runway1.release()

# Airplane 2 can now land
airplane2.request_landing()

# Airplane 1 requests to take off
airplane1.request_takeoff()

# Runway 1 is released and now available
runway1.release()

# Airplane 2 requests to take off
airplane2.request_takeoff()
