/*
Problem Description
We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes k unit time to paint t unit of board. 
The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.Also the length of n boards are in increasing order.
*/
//Code
import java.util.Scanner; 
import java.util.ArrayList;
import java.util.Scanner;
class Solution {
	   
    private static int MOD = 10000003;
   
    private int numberOfPaintersRequired(ArrayList<Integer> boards, long timeUnits) {
        int numberOfPainters = 1;
        long timeUnitsTakenByThePainter = 0;
       
        for(int i = 0; i < boards.size(); i++) {
            timeUnitsTakenByThePainter += (long)boards.get(i);
            if(timeUnitsTakenByThePainter > timeUnits) {
                numberOfPainters++;
                timeUnitsTakenByThePainter = boards.get(i);
            }
        }
        return numberOfPainters;
    }
   
    private long sumOfBoards(ArrayList<Integer> boards) {
        long sum = 0;
        for(Integer board : boards) {
            sum += (long)board;
        }
        return sum;
    }
   
    private long maxOfBoards(ArrayList<Integer> boards) {
        Integer maxi = Integer.MIN_VALUE;
        for(Integer board : boards) {
            maxi = Math.max(maxi, board);
        }
        return (long)maxi;
    }
   
    public int paint(int A, int B, ArrayList<Integer> C) {
        int paintersWeHave = A;
        int timeToPaintEachUnit = B;
        ArrayList<Integer> boards = new ArrayList<>(C);
       
        long lowestTimeUnits = maxOfBoards(boards);
        long highestTimeUnits = sumOfBoards(boards);
        long ansTimeUnits = 0;
       
        while(lowestTimeUnits <= highestTimeUnits) {
            long midTimeUnits = lowestTimeUnits + (highestTimeUnits - lowestTimeUnits) / 2L;
           
            if(numberOfPaintersRequired(boards, midTimeUnits) <= paintersWeHave) {
                ansTimeUnits = midTimeUnits;
                highestTimeUnits = midTimeUnits - 1;
            } else {
                lowestTimeUnits = midTimeUnits + 1;
            }
        }
       
        return (int)(((ansTimeUnits % MOD) * (B % MOD)) % MOD);
    }
}
class Assign1{
	
	public static void main(String a[])
	{
		Solution s = new Solution();
		Scanner sc = new Scanner(System.in); 
		int A = sc.nextInt();
		int B = sc.nextInt();
		System.out.println("Enter number of Boards=");
		int length = sc.nextInt();
		ArrayList<Integer> arrli = new ArrayList<Integer>(length); 
		  
        // Appending the new element at the end of the list 
        for (int i=1; i<=length; i++) 
        { 	
        	int l = sc.nextInt();
        	arrli.add(l);  
        }
        int x=s.paint(A, B, arrli);
		System.out.print("Minimum Time ="+x);
		
		
	}
}
