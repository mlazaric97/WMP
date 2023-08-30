
// log 10 
template<class T>
std::vector<T> logspace(T start, T end, int size)
{
	std::vector<T> ls(size,0); 
	T space = (end - start)/(size-1);
	for (int i{}; i <= size; ++i)
	{
		ls[i] = pow(10,start + i*space); 

	}
	return ls;
}
