#ifndef  PACK_CPP
# define PACK_CPP

template <typename T, typename... Types> void Pack(T firstArg, Types... args);

template <typename T, typename... Types> void Pack(T firstArg, Types... args){
    if (sizeof...(args) > 0) { // if runtime if: args is not empty
        Pack(args...);
    }
}

#endif

