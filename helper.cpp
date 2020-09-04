const int data_length = 10;
int dataset[data_length];

class HelperClass
{
    public:
    void print_array(int *array_to_print, int length_of_array)
    {
        printf("------------------------------------");
        printf("\n\nArray:");
        printf("\n\n");
        for(int i = 0; i < length_of_array; i++)
        {
            printf("%i\t", array_to_print[i]);
        }
        printf("\n\n");
        printf("------------------------------------");
    }

    bool compare_two_arrays(int *array_one, int *array_two, int array_length)
    {
        for(size_t i = 0; i < array_length; i++)
        {
            if(array_one[i] != array_two[i])
            {
                //std::cout << i << "\t" << array_one[i] << "\t" << array_two[i] << "\n\n";
                return false;
            }
        }
        
        return true;
    }

    void generate()
    {
        time_t t;
        srand((unsigned) time(&t));
        //Random Number Generator:
        int lower = 1;
        int upper = 100000000;
        //std::cout << "\nUpper Limit: " << upper;
        for (int i = 1; i <= data_length; i++)
        {
            int random_number = (rand() % (upper - lower + 1)) + lower;
            dataset[i] = random_number;
        }
    }

    bool check_if_sorted(int *input_array, int array_size)
    {    
        for(int i = 0; i < array_size - 1 ; i++) 
        {
            //printf("\n Comparing: %i with %i", input_array[i], input_array[i+1]);
            if(input_array[i] > input_array[i+1])
            {
                printf("\n\n\nArray is not sorted at: %i \n", i);
                return false;
            }
        }
        printf("\nArray is sorted\n");
        return true;
    }
};