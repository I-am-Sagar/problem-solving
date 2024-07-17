class OrderState {
    nextState(order) {
        throw new Error('nextState method should be implemented');
    }
    
    prevState(order) {
        throw new Error('prevState method should be implemented');
    }

    toString() {
        throw new Error('toString method should be implemented');
    }
}

class NewOrderState extends OrderState {
    nextState(order) {
        order.state = new ProcessingOrderState();
    }

    prevState(order) {
        console.log("The order is already in the initial state.");
    }

    toString() {
        return 'New Order';
    }
}

class ProcessingOrderState extends OrderState {
    nextState(order) {
        order.state = new ShippedOrderState();
    }

    prevState(order) {
        order.state = new NewOrderState();
    }

    toString() {
        return 'Processing Order';
    }
}

class ShippedOrderState extends OrderState {
    nextState(order) {
        order.state = new DeliveredOrderState();
    }

    prevState(order) {
        order.state = new ProcessingOrderState();
    }

    toString() {
        return 'Shipped Order';
    }
}

class DeliveredOrderState extends OrderState {
    nextState(order) {
        console.log("The order is already in the final state.");
    }

    prevState(order) {
        order.state = new ShippedOrderState();
    }

    toString() {
        return 'Delivered Order';
    }
}

class Order {
    constructor() {
        this.state = new NewOrderState();
    }
    
    nextState() {
        this.state.nextState(this);
    }
    
    prevState() {
        this.state.prevState(this);
    }
    
    toString() {
        return `Order is currently in '${this.state.toString()}' state.`;
    }
}

// Example Usage
const order = new Order();
console.log(order.toString());  // Output: Order is currently in 'New Order' state.

order.nextState();
console.log(order.toString());  // Output: Order is currently in 'Processing Order' state.

order.nextState();
console.log(order.toString());  // Output: Order is currently in 'Shipped Order' state.

order.nextState();
console.log(order.toString());  // Output: Order is currently in 'Delivered Order' state.

order.prevState();
console.log(order.toString());  // Output: Order is currently in 'Shipped Order' state.

order.prevState();
console.log(order.toString());  // Output: Order is currently in 'Processing Order' state.

order.prevState();
console.log(order.toString());  // Output: Order is currently in 'New Order' state.
