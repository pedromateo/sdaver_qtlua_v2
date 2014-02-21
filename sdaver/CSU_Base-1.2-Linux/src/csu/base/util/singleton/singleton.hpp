  #ifndef SINGLETON_HPP
  #define SINGLETON_HPP

  namespace csu{
    namespace base{
	namespace util{
	  namespace singleton{

	      ///
	      /// Singleton
	      ///

	      template<typename T>
	      class Singleton
	      {
		public:
	      static T* instance(T* t = 0)
	      {
		static T* instance_ = NULL;
		if (t!= 0)
		    instance_ = t;
		return instance_;
	      }
	      };

	  }//singleton
	}//util
    }//lib
  }//csu

  #endif // SINGLETON_HPP
