// OrderState.java
public interface OrderState {
    void nextState(Order order);
    void prevState(Order order);
    String toString();
}

// NewOrderState.java
public class NewOrderState implements OrderState {
    @Override
    public void nextState(Order order) {
        order.setState(new ProcessingOrderState());
    }

    @Override
    public void prevState(Order order) {
        System.out.println("The order is already in the initial state.");
    }

    @Override
    public String toString() {
        return "New Order";
    }
}

// ProcessingOrderState.java
public class ProcessingOrderState implements OrderState {
    @Override
    public void nextState(Order order) {
        order.setState(new ShippedOrderState());
    }

    @Override
    public void prevState(Order order) {
        order.setState(new NewOrderState());
    }

    @Override
    public String toString() {
        return "Processing Order";
    }
}

// ShippedOrderState.java
public class ShippedOrderState implements OrderState {
    @Override
    public void nextState(Order order) {
        order.setState(new DeliveredOrderState());
    }

    @Override
    public void prevState(Order order) {
        order.setState(new ProcessingOrderState());
    }

    @Override
    public String toString() {
        return "Shipped Order";
    }
}

// DeliveredOrderState.java
public class DeliveredOrderState implements OrderState {
    @Override
    public void nextState(Order order) {
        System.out.println("The order is already in the final state.");
    }

    @Override
    public void prevState(Order order) {
        order.setState(new ShippedOrderState());
    }

    @Override
    public String toString() {
        return "Delivered Order";
    }
}

// Order.java
public class Order {
    private OrderState state;

    public Order() {
        state = new NewOrderState();
    }

    public void setState(OrderState state) {
        this.state = state;
    }

    public void nextState() {
        state.nextState(this);
    }

    public void prevState() {
        state.prevState(this);
    }

    @Override
    public String toString() {
        return "Order is currently in '" + state + "' state.";
    }

    public static void main(String[] args) {
        Order order = new Order();
        System.out.println(order);  // Output: Order is currently in 'New Order' state.

        order.nextState();
        System.out.println(order);  // Output: Order is currently in 'Processing Order' state.

        order.nextState();
        System.out.println(order);  // Output: Order is currently in 'Shipped Order' state.

        order.nextState();
        System.out.println(order);  // Output: Order is currently in 'Delivered Order' state.

        order.prevState();
        System.out.println(order);  // Output: Order is currently in 'Shipped Order' state.

        order.prevState();
        System.out.println(order);  // Output: Order is currently in 'Processing Order' state.

        order.prevState();
        System.out.println(order);  // Output: Order is currently in 'New Order' state.
    }
}
