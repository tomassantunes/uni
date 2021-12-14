public class Dog extends Pet 
{
    private int weight;

    public Dog(String name) 
    {
        super(name, "d");
    }

    public void setWeight(int x) {
        this.weight = x;
    }

    public int getWeight() {
        return weight;
    }

    public String toString() {
        return getSpecie() + " " + getName() + "| " + weight; 
    }
}