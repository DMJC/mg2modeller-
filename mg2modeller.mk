##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=mg2modeller
ConfigurationName      :=Debug
WorkspacePath          :=/home/james/development/mg2modeller/mg2modeller++
ProjectPath            :=/home/james/development/mg2modeller/mg2modeller++
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=James Carthew
Date                   :=08/20/17
CodeLitePath           :=/home/james/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="mg2modeller.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -rdynamic $(shell pkg-config --libs gtkmm-3.0 glew gl)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall -O0 $(shell pkg-config --cflags gtkmm-3.0 glew gl) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_view.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tools.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_primitive.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_preferences.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_plane.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_object.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_math3d.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_light.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_gui.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_edit.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_display.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_geometry.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_material.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_normal.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_animation.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_texture.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/src_render.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_tdsgui.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_tsgui.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_callbacks.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/src_view.cpp$(ObjectSuffix): src/view.cpp $(IntermediateDirectory)/src_view.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/view.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_view.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_view.cpp$(DependSuffix): src/view.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_view.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_view.cpp$(DependSuffix) -MM src/view.cpp

$(IntermediateDirectory)/src_view.cpp$(PreprocessSuffix): src/view.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_view.cpp$(PreprocessSuffix) src/view.cpp

$(IntermediateDirectory)/src_tools.cpp$(ObjectSuffix): src/tools.cpp $(IntermediateDirectory)/src_tools.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/tools.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tools.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tools.cpp$(DependSuffix): src/tools.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_tools.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_tools.cpp$(DependSuffix) -MM src/tools.cpp

$(IntermediateDirectory)/src_tools.cpp$(PreprocessSuffix): src/tools.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tools.cpp$(PreprocessSuffix) src/tools.cpp

$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix): src/scene.cpp $(IntermediateDirectory)/src_scene.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/scene.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_scene.cpp$(DependSuffix): src/scene.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_scene.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_scene.cpp$(DependSuffix) -MM src/scene.cpp

$(IntermediateDirectory)/src_scene.cpp$(PreprocessSuffix): src/scene.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_scene.cpp$(PreprocessSuffix) src/scene.cpp

$(IntermediateDirectory)/src_primitive.cpp$(ObjectSuffix): src/primitive.cpp $(IntermediateDirectory)/src_primitive.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/primitive.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_primitive.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_primitive.cpp$(DependSuffix): src/primitive.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_primitive.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_primitive.cpp$(DependSuffix) -MM src/primitive.cpp

$(IntermediateDirectory)/src_primitive.cpp$(PreprocessSuffix): src/primitive.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_primitive.cpp$(PreprocessSuffix) src/primitive.cpp

$(IntermediateDirectory)/src_preferences.cpp$(ObjectSuffix): src/preferences.cpp $(IntermediateDirectory)/src_preferences.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/preferences.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_preferences.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_preferences.cpp$(DependSuffix): src/preferences.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_preferences.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_preferences.cpp$(DependSuffix) -MM src/preferences.cpp

$(IntermediateDirectory)/src_preferences.cpp$(PreprocessSuffix): src/preferences.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_preferences.cpp$(PreprocessSuffix) src/preferences.cpp

$(IntermediateDirectory)/src_plane.cpp$(ObjectSuffix): src/plane.cpp $(IntermediateDirectory)/src_plane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/plane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_plane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_plane.cpp$(DependSuffix): src/plane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_plane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_plane.cpp$(DependSuffix) -MM src/plane.cpp

$(IntermediateDirectory)/src_plane.cpp$(PreprocessSuffix): src/plane.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_plane.cpp$(PreprocessSuffix) src/plane.cpp

$(IntermediateDirectory)/src_object.cpp$(ObjectSuffix): src/object.cpp $(IntermediateDirectory)/src_object.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/object.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_object.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_object.cpp$(DependSuffix): src/object.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_object.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_object.cpp$(DependSuffix) -MM src/object.cpp

$(IntermediateDirectory)/src_object.cpp$(PreprocessSuffix): src/object.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_object.cpp$(PreprocessSuffix) src/object.cpp

$(IntermediateDirectory)/src_math3d.cpp$(ObjectSuffix): src/math3d.cpp $(IntermediateDirectory)/src_math3d.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/math3d.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_math3d.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_math3d.cpp$(DependSuffix): src/math3d.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_math3d.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_math3d.cpp$(DependSuffix) -MM src/math3d.cpp

$(IntermediateDirectory)/src_math3d.cpp$(PreprocessSuffix): src/math3d.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_math3d.cpp$(PreprocessSuffix) src/math3d.cpp

$(IntermediateDirectory)/src_light.cpp$(ObjectSuffix): src/light.cpp $(IntermediateDirectory)/src_light.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/light.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_light.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_light.cpp$(DependSuffix): src/light.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_light.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_light.cpp$(DependSuffix) -MM src/light.cpp

$(IntermediateDirectory)/src_light.cpp$(PreprocessSuffix): src/light.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_light.cpp$(PreprocessSuffix) src/light.cpp

$(IntermediateDirectory)/src_gui.cpp$(ObjectSuffix): src/gui.cpp $(IntermediateDirectory)/src_gui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui.cpp$(DependSuffix): src/gui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui.cpp$(DependSuffix) -MM src/gui.cpp

$(IntermediateDirectory)/src_gui.cpp$(PreprocessSuffix): src/gui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui.cpp$(PreprocessSuffix) src/gui.cpp

$(IntermediateDirectory)/src_edit.cpp$(ObjectSuffix): src/edit.cpp $(IntermediateDirectory)/src_edit.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/edit.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_edit.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_edit.cpp$(DependSuffix): src/edit.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_edit.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_edit.cpp$(DependSuffix) -MM src/edit.cpp

$(IntermediateDirectory)/src_edit.cpp$(PreprocessSuffix): src/edit.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_edit.cpp$(PreprocessSuffix) src/edit.cpp

$(IntermediateDirectory)/src_display.cpp$(ObjectSuffix): src/display.cpp $(IntermediateDirectory)/src_display.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/display.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_display.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_display.cpp$(DependSuffix): src/display.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_display.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_display.cpp$(DependSuffix) -MM src/display.cpp

$(IntermediateDirectory)/src_display.cpp$(PreprocessSuffix): src/display.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_display.cpp$(PreprocessSuffix) src/display.cpp

$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix): src/cube.cpp $(IntermediateDirectory)/src_cube.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/cube.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_cube.cpp$(DependSuffix): src/cube.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_cube.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_cube.cpp$(DependSuffix) -MM src/cube.cpp

$(IntermediateDirectory)/src_cube.cpp$(PreprocessSuffix): src/cube.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_cube.cpp$(PreprocessSuffix) src/cube.cpp

$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix): src/camera.cpp $(IntermediateDirectory)/src_camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_camera.cpp$(DependSuffix): src/camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_camera.cpp$(DependSuffix) -MM src/camera.cpp

$(IntermediateDirectory)/src_camera.cpp$(PreprocessSuffix): src/camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_camera.cpp$(PreprocessSuffix) src/camera.cpp

$(IntermediateDirectory)/src_geometry.cpp$(ObjectSuffix): src/geometry.cpp $(IntermediateDirectory)/src_geometry.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/geometry.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_geometry.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_geometry.cpp$(DependSuffix): src/geometry.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_geometry.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_geometry.cpp$(DependSuffix) -MM src/geometry.cpp

$(IntermediateDirectory)/src_geometry.cpp$(PreprocessSuffix): src/geometry.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_geometry.cpp$(PreprocessSuffix) src/geometry.cpp

$(IntermediateDirectory)/src_material.cpp$(ObjectSuffix): src/material.cpp $(IntermediateDirectory)/src_material.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/material.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_material.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_material.cpp$(DependSuffix): src/material.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_material.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_material.cpp$(DependSuffix) -MM src/material.cpp

$(IntermediateDirectory)/src_material.cpp$(PreprocessSuffix): src/material.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_material.cpp$(PreprocessSuffix) src/material.cpp

$(IntermediateDirectory)/src_normal.cpp$(ObjectSuffix): src/normal.cpp $(IntermediateDirectory)/src_normal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/normal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_normal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_normal.cpp$(DependSuffix): src/normal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_normal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_normal.cpp$(DependSuffix) -MM src/normal.cpp

$(IntermediateDirectory)/src_normal.cpp$(PreprocessSuffix): src/normal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_normal.cpp$(PreprocessSuffix) src/normal.cpp

$(IntermediateDirectory)/src_animation.cpp$(ObjectSuffix): src/animation.cpp $(IntermediateDirectory)/src_animation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/animation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_animation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_animation.cpp$(DependSuffix): src/animation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_animation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_animation.cpp$(DependSuffix) -MM src/animation.cpp

$(IntermediateDirectory)/src_animation.cpp$(PreprocessSuffix): src/animation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_animation.cpp$(PreprocessSuffix) src/animation.cpp

$(IntermediateDirectory)/src_texture.cpp$(ObjectSuffix): src/texture.cpp $(IntermediateDirectory)/src_texture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_texture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_texture.cpp$(DependSuffix): src/texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_texture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_texture.cpp$(DependSuffix) -MM src/texture.cpp

$(IntermediateDirectory)/src_texture.cpp$(PreprocessSuffix): src/texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_texture.cpp$(PreprocessSuffix) src/texture.cpp

$(IntermediateDirectory)/src_render.cpp$(ObjectSuffix): src/render.cpp $(IntermediateDirectory)/src_render.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/render.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_render.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_render.cpp$(DependSuffix): src/render.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_render.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_render.cpp$(DependSuffix) -MM src/render.cpp

$(IntermediateDirectory)/src_render.cpp$(PreprocessSuffix): src/render.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_render.cpp$(PreprocessSuffix) src/render.cpp

$(IntermediateDirectory)/src_gui_tdsgui.cpp$(ObjectSuffix): src/gui/tdsgui.cpp $(IntermediateDirectory)/src_gui_tdsgui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/tdsgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_tdsgui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_tdsgui.cpp$(DependSuffix): src/gui/tdsgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_tdsgui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_tdsgui.cpp$(DependSuffix) -MM src/gui/tdsgui.cpp

$(IntermediateDirectory)/src_gui_tdsgui.cpp$(PreprocessSuffix): src/gui/tdsgui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_tdsgui.cpp$(PreprocessSuffix) src/gui/tdsgui.cpp

$(IntermediateDirectory)/src_gui_tsgui.cpp$(ObjectSuffix): src/gui/tsgui.cpp $(IntermediateDirectory)/src_gui_tsgui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/tsgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_tsgui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_tsgui.cpp$(DependSuffix): src/gui/tsgui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_tsgui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_tsgui.cpp$(DependSuffix) -MM src/gui/tsgui.cpp

$(IntermediateDirectory)/src_gui_tsgui.cpp$(PreprocessSuffix): src/gui/tsgui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_tsgui.cpp$(PreprocessSuffix) src/gui/tsgui.cpp

$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(ObjectSuffix): src/gui/tdsgui_callbacks.cpp $(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/tdsgui_callbacks.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(DependSuffix): src/gui/tdsgui_callbacks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(DependSuffix) -MM src/gui/tdsgui_callbacks.cpp

$(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(PreprocessSuffix): src/gui/tdsgui_callbacks.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_tdsgui_callbacks.cpp$(PreprocessSuffix) src/gui/tdsgui_callbacks.cpp

$(IntermediateDirectory)/src_gui_callbacks.cpp$(ObjectSuffix): src/gui/callbacks.cpp $(IntermediateDirectory)/src_gui_callbacks.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/callbacks.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_callbacks.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_callbacks.cpp$(DependSuffix): src/gui/callbacks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_callbacks.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_callbacks.cpp$(DependSuffix) -MM src/gui/callbacks.cpp

$(IntermediateDirectory)/src_gui_callbacks.cpp$(PreprocessSuffix): src/gui/callbacks.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_callbacks.cpp$(PreprocessSuffix) src/gui/callbacks.cpp

$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(ObjectSuffix): src/gui/tsgui_callbacks.cpp $(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/tsgui_callbacks.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(DependSuffix): src/gui/tsgui_callbacks.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(DependSuffix) -MM src/gui/tsgui_callbacks.cpp

$(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(PreprocessSuffix): src/gui/tsgui_callbacks.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_tsgui_callbacks.cpp$(PreprocessSuffix) src/gui/tsgui_callbacks.cpp

$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(ObjectSuffix): src/gui/mg2toolbutton.cpp $(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/james/development/mg2modeller/mg2modeller++/src/gui/mg2toolbutton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(DependSuffix): src/gui/mg2toolbutton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(DependSuffix) -MM src/gui/mg2toolbutton.cpp

$(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(PreprocessSuffix): src/gui/mg2toolbutton.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_gui_mg2toolbutton.cpp$(PreprocessSuffix) src/gui/mg2toolbutton.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


