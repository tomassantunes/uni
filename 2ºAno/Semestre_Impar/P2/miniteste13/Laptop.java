public class Laptop extends Device{
    private String brand;
    private double weight;
    private boolean risc;
    
    public Laptop(String brand, double weight, boolean risc) {
        super(brand, weight, 32768);
        this.risc = risc;        
    }
    
    public boolean isRisc() {
        return risc;
    }

    @Override
    public boolean isHeavy() {
        if (getWeight() > 750) 
            return true;
        else
            return false;
    }
}
