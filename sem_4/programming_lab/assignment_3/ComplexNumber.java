public class ComplexNumber {
    double real;
    double img;

    public ComplexNumber(double real, double img) {
        this.real = real;
        this.img = img;
    }

    public ComplexNumber() {
        this(0, 0);
    }

    @Override
    public String toString() {
        String formattedReal = String.format("%.4f", this.real);
        String formattedImg = String.format("%.4f", this.img);
        if (this.img > 0)
            return formattedReal + "+" + formattedImg + "i";
        else
            return formattedReal + formattedImg + "i";
    }

    public void add(double real, double img) {
        this.real += real;
        this.img += img;
    }

    public void add(ComplexNumber cn) {
        this.real += cn.real;
        this.img += cn.img;
    }
}