#include <typeinfo>

template<typename T>
T& Resourcemanager::Get(const std::string& path)
{
	std::string name = typeid(T).name()+path; // typeid makes different resources of different types with the same filename possible (most likely useless ;-) )
	try {
		return myResources.at(name).Get<T>();
	}
	catch(...) {
		myResources[name].Load<T>(path);
		return myResources[name].Get<T>();
	}
}
