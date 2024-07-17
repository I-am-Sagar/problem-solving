import java.util.ArrayList;
import java.util.List;

class TowerMediator {
    private List<Runway> runways;
    private List<Airplane> airplanes;

    public TowerMediator() {
        this.runways = new ArrayList<>();
        this.airplanes = new ArrayList<>();
    }

    public void addRunway(Runway runway) {
        runways.add(runway);
    }

    public void addAirplane(Airplane airplane) {
        airplanes.add(airplane);
    }

    public void requestToLand(Airplane airplane) {
        for (Runway runway : runways) {
            if (runway.isAvailable()) {
                runway.land(airplane);
                return;
            }
        }
        System.out.println("All runways are busy, " + airplane.getName() + " cannot land now.");
    }

    public void requestToTakeoff(Airplane airplane) {
        for (Runway runway : runways) {
            if (runway.isAvailable()) {
                runway.takeoff(airplane);
                return;
            }
        }
        System.out.println("All runways are busy, " + airplane.getName() + " cannot take off now.");
    }
}

class Runway {
    private String name;
    private boolean isAvailable;

    public Runway(String name) {
        this.name = name;
        this.isAvailable = true;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void land(Airplane airplane) {
        if (isAvailable) {
            System.out.println(airplane.getName() + " is landing on " + name + ".");
            isAvailable = false;
            airplane.land();
        } else {
            System.out.println(name + " is currently occupied.");
        }
    }

    public void takeoff(Airplane airplane) {
        if (isAvailable) {
            System.out.println(airplane.getName() + " is taking off from " + name + ".");
            isAvailable = false;
            airplane.takeoff();
        } else {
            System.out.println(name + " is currently occupied.");
        }
    }

    public void release() {
        isAvailable = true;
        System.out.println(name + " is now available.");
    }
}

class Airplane {
    private String name;
    private TowerMediator mediator;
    private boolean isFlying;

    public Airplane(String name, TowerMediator mediator) {
        this.name = name;
        this.mediator = mediator;
        this.isFlying = false;
    }

    public String getName() {
        return name;
    }

    public void requestLanding() {
        System.out.println(name + " is requesting to land.");
        mediator.requestToLand(this);
    }

    public void requestTakeoff() {
        System.out.println(name + " is requesting to take off.");
        mediator.requestToTakeoff(this);
    }

    public void land() {
        isFlying = false;
        System.out.println(name + " has landed.");
    }

    public void takeoff() {
        isFlying = true;
        System.out.println(name + " has taken off.");
    }
}

public class Main {
    public static void main(String[] args) {
        TowerMediator mediator = new TowerMediator();

        Runway runway1 = new Runway("Runway 1");
        Runway runway2 = new Runway("Runway 2");

        mediator.addRunway(runway1);
        mediator.addRunway(runway2);

        Airplane airplane1 = new Airplane("Airplane 1", mediator);
        Airplane airplane2 = new Airplane("Airplane 2", mediator);

        mediator.addAirplane(airplane1);
        mediator.addAirplane(airplane2);

        // Airplane 1 requests to land
        airplane1.requestLanding();

        // Airplane 2 requests to land
        airplane2.requestLanding();

        // Runway 1 is released and now available
        runway1.release();

        // Airplane 2 can now land
        airplane2.requestLanding();

        // Airplane 1 requests to take off
        airplane1.requestTakeoff();

        // Runway 1 is released and now available
        runway1.release();

        // Airplane 2 requests to take off
        airplane2.requestTakeoff();
    }
}
