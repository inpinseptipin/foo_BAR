import java.util.*;

/*	KnapSack Problem Greedy Approach  Solution Implementation In Java 
	@Satyarth Arora
*/   

public class knapsack
{
	//Random Number Generator
	public static int retRandom(int range,int min)
	{
		return (int)(Math.random()*range)+min;
	}

	//Initializes HashTable with Weight and Value of the Items
	public static void initHouse(int n,Hashtable<Integer,Integer> val)
	{
		for(int i=0;i<n;i++)
		{
			val.put(retRandom(200,50),retRandom(200,50)); //Weight then Value
		}
	}


	//Calculates Ratios of the Weight According to the Values and arranges them in descending order 
	public static void ratioCalculator(TreeMap<Float,Integer> ratio,Hashtable<Integer,Integer> val)
	{
		Iterator valKeyIterate=val.keySet().iterator();
		Iterator valValueIterate=val.values().iterator();

		int weight,value;

		while(valKeyIterate.hasNext() && valValueIterate.hasNext())
		{
			//System.out.println("HashCode : " + valKeyIterate.next().hashCode());
			weight=valKeyIterate.next().hashCode();
			value=valValueIterate.next().hashCode();
			ratio.put((float)value/weight,weight);
		}
	} 


	//Puts the Items in the bag
	public static void fillBag(int capacity,TreeMap<Float,Integer> ratio)
	{
		int weight;
		float currentRatio;
		int x=0;
		int totalValue=0;
		
		
		List<Integer> bag=new ArrayList<Integer>();
		Iterator valKeyIterate=ratio.keySet().iterator();
		Iterator valValueIterate=ratio.values().iterator();
		

		while(x<=capacity && valKeyIterate.hasNext() && valValueIterate.hasNext())
		{
			currentRatio=Float.parseFloat(valKeyIterate.next().toString());
			weight=valValueIterate.next().hashCode();
			if(x+weight<=900)
			{
				x+=weight;
				bag.add(weight);
				totalValue+=(int)(currentRatio*weight);	
			}
			
		}

		System.out.println("Total Value of the Items : " + totalValue +"\n\n");
		System.out.println("Total Weight : " + x);
		System.out.println(bag);
	}

	public static void main(String[] args)
	{
		int capacity=900;
		int n=retRandom(10,5);
		
		Hashtable<Integer,Integer> val=new Hashtable<Integer,Integer>();
		TreeMap<Float,Integer> ratio=new TreeMap<Float,Integer>(Collections.reverseOrder());
		initHouse(n,val);

		Iterator keyIterate=val.keySet().iterator();
		Iterator valueIterate=val.values().iterator();


		ratioCalculator(ratio,val);
		fillBag(capacity,ratio);
		
	}
}