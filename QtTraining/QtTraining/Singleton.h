#pragma once

template<typename T>
class Singleton
{
public:
	static T* CreateInstance()
	{
		if (nullptr != m_instance)
		{
			return m_instance;
		}
		m_instance = new T();
		return m_instance;
	}

	static T* GetInstance()
	{
		if (nullptr == m_instance)
		{
			return CreateInstance();
		}
		return m_instance;
	}

	static void DestroyInstance()
	{
		if (nullptr != m_instance)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}

	static void SetInstance(T* instance)
	{
		m_instance = instance;
	}


protected:

	static T* m_instance;

};

template<typename T>
T* Singleton<T>::m_instance = nullptr;

