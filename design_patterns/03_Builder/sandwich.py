class Sandwich:
    def __init__(self):
        self.ingredients = []
        self.bread = ""
        self.condiments = []

    def add_ingredient(self, ingredient):
        self.ingredients.append(ingredient)

    def set_bread(self, bread):
        self.bread = bread

    def add_condiment(self, condiment):
        self.condiments.append(condiment)

    def __str__(self):
        return f"Sandwich with {', '.join(self.ingredients)} on {self.bread} bread with {', '.join(self.condiments)}."


class SandwichBuilder:
    def __init__(self):
        self.sandwich = Sandwich()

    def add_ingredients(self, ingredients):
        for ingredient in ingredients:
            self.sandwich.add_ingredient(ingredient)
        return self

    def add_bread(self, bread):
        self.sandwich.set_bread(bread)
        return self

    def add_condiments(self, condiments):
        for condiment in condiments:
            self.sandwich.add_condiment(condiment)
        return self

    def build(self):
        return self.sandwich


# Client code
builder = SandwichBuilder()
sandwich = builder.add_ingredients(["Ham", "Cheese"]).add_bread("Wheat").add_condiments(["Mayo", "Mustard"]).build()

print(sandwich)


