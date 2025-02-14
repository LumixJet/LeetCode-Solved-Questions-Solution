class ProductOfNumbers {
public:
    vector<int> arr; //making an array as global vector so that it can be accessed from every function
    ProductOfNumbers() 
    {
        //As it's a constructor it does nothing    
    }
    
    void add(int num) //function to add number in vector
    {
        arr.push_back(num); //pushing number in vector
    }
    
    int getProduct(int k) 
    {
        int n = arr.size();
        int prod = 1;
        for(int i=n-k;i<n;i++) //function to find the product for last k numbers which are present in array
        {
            prod *= arr[i]; //last k elements present in array product
        }
        return prod; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */