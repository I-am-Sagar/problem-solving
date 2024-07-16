class Sandwich {
    constructor() {
        this.ingredients = [];
        this.bread = "";
        this.condiments = [];
    }

    addIngredient(ingredient) {
        this.ingredients.push(ingredient);
    }

    setBread(bread) {
        this.bread = bread;
    }

    addCondiment(condiment) {
        this.condiments.push(condiment);
    }

    toString() {
        return `Sandwich with ${this.ingredients.join(", ")} on ${this.bread} bread with ${this.condiments.join(", ")}.`;
    }
}

class SandwichBuilder {
    constructor() {
        this.sandwich = new Sandwich();
    }

    addIngredients(ingredients) {
        for (let ingredient of ingredients) {
            this.sandwich.addIngredient(ingredient);
        }
        return this;
    }

    addBread(bread) {
        this.sandwich.setBread(bread);
        return this;
    }

    addCondiments(condiments) {
        for (let condiment of condiments) {
            this.sandwich.addCondiment(condiment);
        }
        return this;
    }

    build() {
        return this.sandwich;
    }
}

// Client code
const builder = new SandwichBuilder();

const sandwich = builder
    .addBread("Wheat")
    .addIngredients(["Ham", "Cheese"])
    .addCondiments(["Mayo", "Mustard"])
    .build();

console.log(sandwich.toString());