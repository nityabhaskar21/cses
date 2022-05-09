package Utility;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class sorting {
    public static void main(String[] args) {
        List<String> l1 = List.of("b", "d", "a");
        List<String> sl1 =  l1.stream().sorted().collect(Collectors.toList());
        System.out.println(sl1);

        //Inplace sorting 
        //List.of() is immutable so we can't use here
        List<String> l2 = Arrays.asList("y", "e", "g"); 
        l2.sort((o1, o2) -> o1.compareTo(o2));
        System.out.println(l2);

        //Inplace sorting 2
        List<String> l3 = Arrays.asList("p", "e", "h"); 
        l3.sort(Comparator.comparing(o -> o));
        System.out.println(l3);
    }
    
}
