from abc import ABC, abstractmethod

class OrderState(ABC):
    @abstractmethod
    def next_state(self, order):
        pass
    
    @abstractmethod
    def prev_state(self, order):
        pass
    
    @abstractmethod
    def __str__(self):
        pass

class NewOrderState(OrderState):
    def next_state(self, order):
        order.state = ProcessingOrderState()

    def prev_state(self, order):
        print("The order is already in the initial state.")

    def __str__(self):
        return "New Order"

class ProcessingOrderState(OrderState):
    def next_state(self, order):
        order.state = ShippedOrderState()

    def prev_state(self, order):
        order.state = NewOrderState()

    def __str__(self):
        return "Processing Order"

class ShippedOrderState(OrderState):
    def next_state(self, order):
        order.state = DeliveredOrderState()

    def prev_state(self, order):
        order.state = ProcessingOrderState()

    def __str__(self):
        return "Shipped Order"

class DeliveredOrderState(OrderState):
    def next_state(self, order):
        print("The order is already in the final state.")

    def prev_state(self, order):
        order.state = ShippedOrderState()

    def __str__(self):
        return "Delivered Order"

class Order:
    def __init__(self):
        self.state = NewOrderState()
        
    def next_state(self):
        self.state.next_state(self)
        
    def prev_state(self):
        self.state.prev_state(self)
        
    def __str__(self):
        return f"Order is currently in '{self.state}' state."


order = Order()
print(order)  # Output: Order is currently in 'New Order' state.

order.next_state()
print(order)  # Output: Order is currently in 'Processing Order' state.

order.next_state()
print(order)  # Output: Order is currently in 'Shipped Order' state.

order.next_state()
print(order)  # Output: Order is currently in 'Delivered Order' state.

order.prev_state()
print(order)  # Output: Order is currently in 'Shipped Order' state.

order.prev_state()
print(order)  # Output: Order is currently in 'Processing Order' state.

order.prev_state()
print(order)  # Output: Order is currently in 'New Order' state.