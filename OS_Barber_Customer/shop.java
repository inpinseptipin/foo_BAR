import java.util.Scanner;
import java.util.Random;
import java.io.*;


class Wrapper
{
	static Boolean chairs[];
	static int chair_pointer;
	static int customer_id;
	static int served_customers;
	
	public static  void init()
	{
		chairs=new Boolean[8];
		for(int i=0;i<8;i++)
		{
			chairs[i]=false;
		}
		customer_id=0;
		chair_pointer=-1;
		served_customers=0;
	}

	public static synchronized void setChair(int position)
	{
		chairs[position]=true;
		customer_id++;
	}

	public static synchronized Boolean retChair()
	{
		chair_pointer++;
		if(chair_pointer==8)
		{
			chair_pointer=0;
		}
		if(chairs[chair_pointer]==false)
		{
			
			return false;
		}
		else
		{
			chairs[chair_pointer]=false;
			chair_pointer++;
			served_customers++;
			return true;
		}
	}

	public static synchronized int chair_available()
	{
		for(int i=0;i<8;i++)
		{
			if(chairs[i]==false)
			{
				return i;
			}
		}
		return -1;
	}

	public static synchronized int retserved()
	{
		return served_customers;
	}

	public static synchronized void log()
	{
		System.out.println("*********************************LOG*****************************");

	}
}

class Customer extends Thread
{
	
	int customer;
	public void enterCustomer()
	{
		Random rand=new Random();
		
	}
	public void run()
	{	
		System.out.println("Customer Thread : " + Thread.currentThread().getId());	
	}
}

class Barber extends Thread
{
	
	public Boolean is_working=false;

	public void run()
	{
		Random rand=new Random();
		while(true)
		{
			try
			{
				System.out.println("**************************ALert From BARBER THREAD***************************\n\n\n");
				if(Wrapper.retChair())
				{
					
					is_working=true;
					Thread.sleep(rand.nextInt(5)*1000);
					is_working=false;
					
					System.out.println("Served Customers : " + Wrapper.retserved()+"\n\n");
					
				}
				else
				{
					System.out.println("Barber Sleeping");
				}
			}
			catch(Exception e)
			{
				e.printStackTrace();
				System.out.println("Barber Thread in Exception");		
			}


		}
	
	}

}

class Barber_schedule extends Thread
{
	
	public void run()
	{

		System.out.println("Barber Schedule Thread :" + Thread.currentThread().getId());
	}

}

class Customer_schedule extends Thread
{
	
	Boolean chairs[];

	int customer_id;
	public Boolean customer_enters()
	{
		Random rand =new Random();
		try
		{
			System.out.println("Customer Enters the SHop \n\n");
			Thread.sleep(rand.nextInt(2)*1000);
				
		}
		catch(Exception e)
		{
			System.out.println("*****************************ERROR in CUSTOMER_ENTERS***********************");
		}
		return rand.nextBoolean();
	}

	public void run()
	{
		//initChairs();
		int x;
		Wrapper wrap;
		while(true)
		{
				//System.out.println("Customer Schedule Thread  :" + Thread.currentThread().getId());
	
			if(customer_enters())
			{
				
				System.out.println("*******************ALERT FROM CUSTOMER_SCHEDULER**************************");
				if((x=Wrapper.chair_available())!=-1)
				{
					
					//chairs[x]=true;
					//wrap=new Wrapper(chairs);
					
					Wrapper.setChair(x);
					System.out.println("Customer Number : " + (++customer_id) + " Seated at Chair Number " + x + "\n\n");
				}
				else
				{
					System.out.println("Customer Number : " + (++customer_id) + " Left the SHop" +"\n\n");
				}
			}
		}

	
	}

}


public class shop 
{
	public static void main(String[] args)
	{
		Customer customer =new Customer();
		Barber barber=new Barber();
		Barber_schedule barber_schedule=new Barber_schedule();
		Customer_schedule customer_schedule=new Customer_schedule();
		Wrapper.init();
		barber.start();
		customer_schedule.start();
		
	}
}