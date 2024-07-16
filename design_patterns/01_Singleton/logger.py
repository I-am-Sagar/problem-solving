import threading

class Logger:
    _instance = None
    _lock = threading.Lock()

    def __new__(cls, *args, **kwargs):
        with cls._lock:
            if not cls._instance:
                cls._instance = super(Logger, cls).__new__(cls)
                cls._instance._initialized = False
        return cls._instance

    def __init__(self):
        if self._initialized:
            return
        self._log_file = "app.log"
        self._initialized = True

    def log(self, message):
        with open(self._log_file, "a") as file:
            file.write(f"{message}\n")

# Example usage
logger1 = Logger()
logger2 = Logger()

logger1.log("Logging from logger1")
logger2.log("Logging from logger2")

print(f"Logger1 and Logger2 are the same instance: {logger1 is logger2}")
