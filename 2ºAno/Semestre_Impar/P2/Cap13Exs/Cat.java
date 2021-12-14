public class Cat extends Pet 
{
    private String coatColor;

    public Cat(String name) {
        super(name, "c");
    }

    public void setCoatColor(String color) {
        this.coatColor = color;
    }

    public String toString() {
        return getSpecie() + " " + getName() + "|" + coatColor; 
    }
}