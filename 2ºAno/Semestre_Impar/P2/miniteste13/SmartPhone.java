import java.lang.Boolean;

public class SmartPhone extends Device {
    private double weight;
    private long IMEI;

    public SmartPhone(double weight, long memory, long imei) {
        super("Bravo de Esmolfe", weight, memory);
        this.IMEI = imei;
    }

    public long getIMEI() {
        return IMEI;
    }

    @Override
    public boolean isHeavy() {
        if(getWeight() > 100) 
            return true;
        else
            return false;
    }
}
