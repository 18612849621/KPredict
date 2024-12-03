# 自定义的函数：查找库
function(find_library_if_exists LIBRARY_PATH_A LIBRARY_PATH_B RESULT_VARIABLE)
    if(EXISTS ${LIBRARY_PATH_A})
        set(${RESULT_VARIABLE} ${LIBRARY_PATH_A} PARENT_SCOPE)
    elseif(EXISTS ${LIBRARY_PATH_B})
        set(${RESULT_VARIABLE} ${LIBRARY_PATH_B} PARENT_SCOPE)
    else()
        message(FATAL_ERROR "Neither shared library nor static library found for ${LIBRARY_PATH_A} and ${LIBRARY_PATH_B}!")
    endif()
endfunction()

