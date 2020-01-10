import java.util.*;
import java.io.*;

class A {
  int x,y;
  A(int x,int y) {
    this.x=x;
    this.y=y;
  }
  void a1() {
    System.out.println("In A");
  }
}

class B extends A {
  int z;
  B(int z) {
    this.z=z;
  }
  void a1() {
    System.out.println("In B");
  }
  void b1() {
    System.out.println("Yay it worked");
  }
}

public class java_test {

  public static void main(String args[]) {
    A a = new B(10);
  }

}
