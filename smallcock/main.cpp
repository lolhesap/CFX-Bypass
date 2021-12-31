#include "core/trace.hpp"
#include "core/network.hpp"

int main()
{
	int choice;

	while (true)
	{
		system("cls");

		std::cout << R"(
                                            
                                                            
                 *//                                          
             .*/****/.       ,***************                 
        *****************************************             
      ******(***************************************          
   .********%#***************************************         
   **************************************************.        
        ////**********************//******************        
                ////*************////*****************        
                   ////*******///////****************         
                       //*****///////*********************    
                          ***.          *********     ******* 
                        *****        ********             ****
                                                          ****
                                                      ,*****  
                             .*************************       

	)" << '\n';

		std::cout << "  [1]  :  " << "clean traces" << std::endl;
		std::cout << "  [2]  :  " << "enable network bypass" << std::endl;
		std::cout << "  [3]  :  " << "disable network bypass" << std::endl;
		std::cin >> choice;

		g_network = std::make_unique<network>();
		g_trace = std::make_unique<trace>();

		switch (choice)
		{
			case 1:
			{
				g_trace->setup();
			}
			break;
			case 2:
			{
				g_network->setup();
			}
			break;
			case 3:
			{
				g_network->destroy();
			}
			break;
		}

		system("Pause");
	}

}
