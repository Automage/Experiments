import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;


public class PolarPlotter extends Canvas {

    int fractalCount = 0;

    final int HEIGHT = 500, WIDTH = 500;
    final int speed = 2;
    int xStart = WIDTH / 2;
    int yStart = HEIGHT / 2;

    Color color = Color.RED;
    BufferedImage img;
    Graphics g;

    public static void main(String[] args) {

        PolarPlotter polarPlotter = new PolarPlotter();
        polarPlotter.img = new BufferedImage(polarPlotter.WIDTH, polarPlotter.HEIGHT, BufferedImage.TYPE_INT_RGB);


        JFrame frame = new JFrame("Polar Plotter");
        frame.setSize(polarPlotter.WIDTH, polarPlotter.HEIGHT);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.add(polarPlotter);
        //frame.setLocation(640 - 250, 400 - 250);
        frame.setVisible(true);

        while (true) {
            polarPlotter.render();
        }


        //System.out.println("end");

    }

    public void render() {

        g = img.createGraphics();
        Graphics2D g2D = (Graphics2D) g;

        //background color
        if (fractalCount == 0) {
            g.setColor(Color.BLACK);
            g.fillRect(0, 0, WIDTH, HEIGHT);
        }

        //Fractal calculation
        //Spiral
        //int xEnd = (int) ((fractalCount / 5) * Math.cos(fractalCount * 0.05) + xStart);
        //int yEnd = (int) ((fractalCount / 5) * Math.sin(fractalCount * 0.05) + yStart);

        //Polar plotter - lissajous figures and roses (see polarToCart function)
        int[] cart = polarToCart(fractalCount);
        int xEnd = cart[0] + 250;
        int yEnd = cart[1] + 250;

        //render
        g.setColor(colorFunction());
        //Draws Lines
        //g.drawLine(xStart, yStart, xEnd, yEnd);

        //Draws Points
        g2D.drawOval(xEnd,yEnd,2,2);

        //Fractal iteration
        fractalCount++;

        try {
            Thread.sleep(speed);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        repaint();
    }

    public void paint(Graphics g) {

        g.drawImage(img, 0, 0, null);

    }

    private Color colorFunction() {

        float hue = (float)(0.5*Math.sin(fractalCount*0.01) + 0.5);
        return Color.getHSBColor(hue, 1,1);

    }

    private int[] polarToCart(int fractalCount) {

        double theta = fractalCount*1;
        int r = (int)(150*Math.cos(6*theta));

        // cos3x Rose
        //int[] cartesian = {(int)(r*Math.cos(theta)), (int)(r*Math.sin(theta))};

        //Lissajous figure
        int[] cartesian = {(int)(100*Math.sin(theta/18)), (int)(100*Math.cos(theta/20))};

        return cartesian;
    }

}
