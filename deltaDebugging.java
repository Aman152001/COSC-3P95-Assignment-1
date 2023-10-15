//Importing all the necessary libraries for the follwing code
import java.util.ArrayList;
import java.util.List;

/*
Class declaration for Delta Debugging
*/
public class deltaDebugging{
    //This function convert the inputstring to uppercase characters to their lowercase counterparts and vice versa. Numeric characters are supposed to remain unchanged. 
	public static String processStrng(String inputStr){
		StringBuilder outputString = new StringBuilder(); // Using StringBuilder to store the output string
		for (char chr : inputStr.toCharArray()){
			if (Character.isUpperCase(chr)){
				outputString.append(Character.toLowerCase(chr));
			}
			else if (Character.isDigit(chr)){
				outputString.append(chr).append(chr); //Bug which duplicates the numeric values
			}
			else{
				outputString.append(Character.toUpperCase(chr));
			}
		}
		return outputString.toString(); //return the output string
	}
//The deltaDebugging function identifies the error values and returns the list of all error value set
	public static List<String> deltaDebugging(String strng, int j){
		List<String> errorValueSet = new ArrayList<>();
		//Base Case
		if (strng.length()==0){
			return errorValueSet;
		}
		//If input string has 1 character and its not equal to process String then add the string to the error value set
		else if(strng.length()==1 && strng.length() != processStrng(strng).length()){
			if (!errorValueSet.contains(strng)){
				errorValueSet.add(strng);
			}
		
		}
		//If it needs further debugging split the string into two parts and recursively perform binary search on each part.
		else if(strng.length()!= processStrng(strng).length()){
			errorValueSet.addAll(deltaDebugging(strng.substring(0,strng.length()/2),j+1));
			errorValueSet.addAll(deltaDebugging(strng.substring(strng.length()/2),j+1));
		}
		//prints the current input string
		if( j==0){
			System.out.println("Error Value in the Set for"+ strng + ": " + errorValueSet+ "\n");

		}
		return errorValueSet; //return the error value set to the input string
	}
	public static void main(String[] args){
	    deltaDebugging("abcdefG1",0);
	    deltaDebugging("CCDDEExy",0);
	    deltaDebugging("1234567b",0);
	    deltaDebugging("8665",0);
	}
}