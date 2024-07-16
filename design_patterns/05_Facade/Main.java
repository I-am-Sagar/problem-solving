// Define the appliance classes
class Light {
    void on() {
        System.out.println("Light is on");
    }

    void off() {
        System.out.println("Light is off");
    }
}

class Television {
    void on() {
        System.out.println("Television is on");
    }

    void off() {
        System.out.println("Television is off");
    }
}

class AirConditioner {
    void on() {
        System.out.println("Air Conditioner is on");
    }

    void off() {
        System.out.println("Air Conditioner is off");
    }
}

// Define the HomeFacade class
class HomeFacade {
    private Light light;
    private Television tv;
    private AirConditioner ac;

    public HomeFacade() {
        this.light = new Light();
        this.tv = new Television();
        this.ac = new AirConditioner();
    }

    public void eveningMode() {
        System.out.println("Setting evening mode...");
        light.on();
        tv.on();
        ac.on();
    }

    public void morningMode() {
        System.out.println("Setting morning mode...");
        light.off();
        tv.off();
        ac.off();
    }
}

// Using the HomeFacade to control appliances
public class Main {
    public static void main(String[] args) {
        HomeFacade home = new HomeFacade();

        // Activating evening mode
        home.eveningMode();
        System.out.println();
        // Activating morning mode
        home.morningMode();
    }
}
