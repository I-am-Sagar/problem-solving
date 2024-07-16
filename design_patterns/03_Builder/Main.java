import java.util.ArrayList;
import java.util.List;

class Sandwich {
    private List<String> ingredients;
    private String bread;
    private List<String> condiments;

    public Sandwich() {
        this.ingredients = new ArrayList<>();
        this.bread = "";
        this.condiments = new ArrayList<>();
    }

    public void addIngredient(String ingredient) {
        this.ingredients.add(ingredient);
    }

    public void setBread(String bread) {
        this.bread = bread;
    }

    public void addCondiment(String condiment) {
        this.condiments.add(condiment);
    }

    @Override
    public String toString() {
        return "Sandwich with " + String.join(", ", this.ingredients) +
               " on " + this.bread + " bread with " + String.join(", ", this.condiments) + ".";
    }
}

class SandwichBuilder {
    private Sandwich sandwich;

    public SandwichBuilder() {
        this.sandwich = new Sandwich();
    }

    public SandwichBuilder addIngredients(List<String> ingredients) {
        for (String ingredient : ingredients) {
            this.sandwich.addIngredient(ingredient);
        }
        return this;
    }

    public SandwichBuilder addBread(String bread) {
        this.sandwich.setBread(bread);
        return this;
    }

    public SandwichBuilder addCondiments(List<String> condiments) {
        for (String condiment : condiments) {
            this.sandwich.addCondiment(condiment);
        }
        return this;
    }

    public Sandwich build() {
        return this.sandwich;
    }
}

public class Main {
    public static void main(String[] args) {
        SandwichBuilder builder = new SandwichBuilder();
        Sandwich sandwich = builder
                .addIngredients(List.of("Ham", "Cheese"))
                .addBread("Wheat")
                .addCondiments(List.of("Mayo", "Mustard"))
                .build();

        System.out.println(sandwich.toString());
    }
}
