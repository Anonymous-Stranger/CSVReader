##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=_CSVReader
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Akash\Documents\Programming\_codelite\c++"
ProjectPath            := "C:\Users\Akash\Documents\Programming\_codelite\c++\_CSVReader"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Akash
Date                   :=26/08/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :="C:/Program Files (x86)/LLVM/bin/clang++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/LLVM/bin/clang++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="_CSVReader.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++ $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/mingw32 $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/backward $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include $(IncludeSwitch)c:/MinGW/include $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include-fixed $(IncludeSwitch)c:/MinGW/mingw32/include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files (x86)/LLVM/bin/llvm-ar.exe" rcu
CXX      := "C:/Program Files (x86)/LLVM/bin/clang++.exe"
CC       := "C:/Program Files (x86)/LLVM/bin/clang.exe"
CXXFLAGS := -std=c++11 -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/LLVM/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/_CSVReader__test.cpp$(ObjectSuffix) $(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(ObjectSuffix) $(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug"
	@echo rebuilt > "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug/_CSVReader"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/_CSVReader__test.cpp$(ObjectSuffix): ../../../Eclipse/C++/_CSVReader/_test.cpp $(IntermediateDirectory)/_CSVReader__test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/Eclipse/C++/_CSVReader/_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/_CSVReader__test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/_CSVReader__test.cpp$(DependSuffix): ../../../Eclipse/C++/_CSVReader/_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/_CSVReader__test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/_CSVReader__test.cpp$(DependSuffix) -MM "../../../Eclipse/C++/_CSVReader/_test.cpp"

$(IntermediateDirectory)/_CSVReader__test.cpp$(PreprocessSuffix): ../../../Eclipse/C++/_CSVReader/_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/_CSVReader__test.cpp$(PreprocessSuffix) "../../../Eclipse/C++/_CSVReader/_test.cpp"

$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(ObjectSuffix): ../../../Eclipse/C++/_CSVReader/CSVStream.cpp $(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/Eclipse/C++/_CSVReader/CSVStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(DependSuffix): ../../../Eclipse/C++/_CSVReader/CSVStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(DependSuffix) -MM "../../../Eclipse/C++/_CSVReader/CSVStream.cpp"

$(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(PreprocessSuffix): ../../../Eclipse/C++/_CSVReader/CSVStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/_CSVReader_CSVStream.cpp$(PreprocessSuffix) "../../../Eclipse/C++/_CSVReader/CSVStream.cpp"

$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(ObjectSuffix): ../../../Eclipse/C++/_CSVReader/TokenStream.cpp $(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/Eclipse/C++/_CSVReader/TokenStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(DependSuffix): ../../../Eclipse/C++/_CSVReader/TokenStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(DependSuffix) -MM "../../../Eclipse/C++/_CSVReader/TokenStream.cpp"

$(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(PreprocessSuffix): ../../../Eclipse/C++/_CSVReader/TokenStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/_CSVReader_TokenStream.cpp$(PreprocessSuffix) "../../../Eclipse/C++/_CSVReader/TokenStream.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


