#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]){

fstream inputfile;

string buffer;

if(argc > 1){
    cout << "Loading trueSpace Preferences" << endl;
    inputfile.open(argv[1], fstream::in);
	string token;
	string token2;
	string discard;
    int count = 1;
    int quit = 0;
    while ( !inputfile.eof()){
    	while (count != 0){
	    	getline (inputfile, discard);
		    getline (inputfile, discard);
		    count--;
    		//cout << "discarding version header" << endl;
	    }
	    getline (inputfile, buffer);
    	size_t pos = 0;
    	string delimiter = " ";
    	while ((pos = buffer.find(delimiter)) != string::npos || quit == 1) {
    	    token = buffer.substr(0, pos);
    	    token2 = buffer.substr(pos+1, string::npos);
    	    //token2 = token2.erase(token2.length()-1);
	        cout << token << " " << token2 << endl;
	        buffer.erase(0, pos + delimiter.length());
            if (token == "END"){
                buffer.erase (0, string::npos);
                break; // quits our look
            }
	    }

        map<string,int>	m1;
			m1.insert(pair<string, int>("Caligari", 1));
			m1.insert(pair<string, int>("cfig", 2));
			m1.insert(pair<string, int>("savestate", 3));
			m1.insert(pair<string, int>("numstates", 4));
			m1.insert(pair<string, int>("Settings", 5));
			m1.insert(pair<string, int>("Strips", 6));
			m1.insert(pair<string, int>("BCubeThreshold", 7));
			m1.insert(pair<string, int>("PEditDraw", 8));
			m1.insert(pair<string, int>("PEditSubDiv", 9));
			m1.insert(pair<string, int>("DeformDraw", 10));
			m1.insert(pair<string, int>("PathHandles", 11));
			m1.insert(pair<string, int>("KeyOffset", 12));
			m1.insert(pair<string, int>("SweepSegments", 13));
			m1.insert(pair<string, int>("QDiv", 14));
			m1.insert(pair<string, int>("SmoothAngle", 15));
			m1.insert(pair<string, int>("StartupFile", 16));
			m1.insert(pair<string, int>("ProxyServer", 17));
			m1.insert(pair<string, int>("ProxyPort", 18));
			m1.insert(pair<string, int>("VRMLLoadInlines", 19));
			m1.insert(pair<string, int>("RegpolySides", 20));
			m1.insert(pair<string, int>("PPlaneResolution", 21));
			m1.insert(pair<string, int>("PCubeResolution", 22));
			m1.insert(pair<string, int>("PCylinderLatDiv", 23));
			m1.insert(pair<string, int>("PCylinderLongDiv", 24));
			m1.insert(pair<string, int>("PSphereLatDiv", 25));
			m1.insert(pair<string, int>("PSphereLongDiv", 26));
			m1.insert(pair<string, int>("PConeLatDiv", 27));
			m1.insert(pair<string, int>("PConeLongDiv", 28));
			m1.insert(pair<string, int>("PCutConeLatDiv", 29));
			m1.insert(pair<string, int>("PCutConeLongDiv", 30));
			m1.insert(pair<string, int>("PCutConeTopRadius", 31));
			m1.insert(pair<string, int>("PTorusLatDiv", 32));
			m1.insert(pair<string, int>("PTorusLongDiv", 33));
			m1.insert(pair<string, int>("PTorusInnerRadius", 34));
			m1.insert(pair<string, int>("RenderResolution", 35));
			m1.insert(pair<string, int>("RenderWidth", 36));
			m1.insert(pair<string, int>("RenderHeight", 37));
			m1.insert(pair<string, int>("RenderFrameRate", 38));
			m1.insert(pair<string, int>("RenderDepth", 39));
			m1.insert(pair<string, int>("RenderPixelAspect", 40));
			m1.insert(pair<string, int>("BaseFrameRate", 41));
			m1.insert(pair<string, int>("RaytraceThreshold", 42));
			m1.insert(pair<string, int>("RenderFlags", 43));
			m1.insert(pair<string, int>("RenderFilename", 44));
			m1.insert(pair<string, int>("RenderFrame", 45));
			m1.insert(pair<string, int>("PathImageSave", 46));
			m1.insert(pair<string, int>("PathEnvironment", 47));
			m1.insert(pair<string, int>("DXF2DWidth", 48));
			m1.insert(pair<string, int>("DXFFlags", 49));
			m1.insert(pair<string, int>("DXFLayerName", 50));
			m1.insert(pair<string, int>("DXFSegments", 51));
			m1.insert(pair<string, int>("PostScriptCurveRes", 52));
			m1.insert(pair<string, int>("PostScriptFilter", 53));
			m1.insert(pair<string, int>("PostScriptObjectStep", 54));
			m1.insert(pair<string, int>("PostScriptPageStep", 55));
			m1.insert(pair<string, int>("PostScriptFlags", 56));
			m1.insert(pair<string, int>("UnitFlags", 57));
			m1.insert(pair<string, int>("ObjectUnits", 58));
			m1.insert(pair<string, int>("WorldUnits", 59));
			m1.insert(pair<string, int>("DefaultLight", 60));
			m1.insert(pair<string, int>("FieldRenderFlags", 61));
			m1.insert(pair<string, int>("MotionBlurFlags", 62));
			m1.insert(pair<string, int>("MotionBlurLength", 63));
			m1.insert(pair<string, int>("MotionBlurFrames", 64));
			m1.insert(pair<string, int>("3DSSet", 65));
			m1.insert(pair<string, int>("3DSSetPath", 66));
			m1.insert(pair<string, int>("FilterPluginPath", 67));
			m1.insert(pair<string, int>("BackgroundRed", 68));
			m1.insert(pair<string, int>("BackgroundGreen", 69));
			m1.insert(pair<string, int>("BackgroundBlue", 70));
			m1.insert(pair<string, int>("BackgroundAlpha", 71));
			m1.insert(pair<string, int>("BackgroundFilename", 72));
			m1.insert(pair<string, int>("FogRed", 73));
			m1.insert(pair<string, int>("FogGreen", 74));
			m1.insert(pair<string, int>("FogBlue", 75));
			m1.insert(pair<string, int>("FogNear", 76));
			m1.insert(pair<string, int>("FogFar", 77));
			m1.insert(pair<string, int>("FogMax", 78));
			m1.insert(pair<string, int>("GlobalEnvName", 79));
			m1.insert(pair<string, int>("GlobalEnvRed", 80));
			m1.insert(pair<string, int>("GlobalEnvGreen", 81));
			m1.insert(pair<string, int>("GlobalEnvBlue", 82));
			m1.insert(pair<string, int>("OldBackgroundName", 83));
			m1.insert(pair<string, int>("OldEnvName", 84));
			m1.insert(pair<string, int>("DepthFocalDist", 85));
			m1.insert(pair<string, int>("DepthFocus", 86));
			m1.insert(pair<string, int>("DynamicDivideEpsilon", 87));
			m1.insert(pair<string, int>("UndoType", 88));
			m1.insert(pair<string, int>("DXFImportUnits", 89));
			m1.insert(pair<string, int>("ObjectImportFlags", 90));
			m1.insert(pair<string, int>("ObjectImportUnits", 91));
			m1.insert(pair<string, int>("PostScriptImportUnits", 92));
			m1.insert(pair<string, int>("JPEGQuality", 93));
			m1.insert(pair<string, int>("FLICFlags", 94));
			m1.insert(pair<string, int>("TargaFlags", 95));
			m1.insert(pair<string, int>("RenderResPresets", 96));
			m1.insert(pair<string, int>("MetaballsResolution", 97));
			m1.insert(pair<string, int>("MetaballsRenderRes", 98));
			m1.insert(pair<string, int>("MetaballsRefresh", 99));
			m1.insert(pair<string, int>("Settings2", 100));
			m1.insert(pair<string, int>("Properties", 101));
			m1.insert(pair<string, int>("PlastiformResolution", 102));
			m1.insert(pair<string, int>("VisibleRes", 103));
			m1.insert(pair<string, int>("PreviewName", 104));
			m1.insert(pair<string, int>("PreviewSel", 105));
			m1.insert(pair<string, int>("PreviewFrom", 106));
			m1.insert(pair<string, int>("PreviewTo", 107));
			m1.insert(pair<string, int>("PreviewStep", 108));
			m1.insert(pair<string, int>("PreviewOpt", 109));
			m1.insert(pair<string, int>("PreviewViewName", 110));
			m1.insert(pair<string, int>("NailColor", 111));
			m1.insert(pair<string, int>("PointsColor", 112));
			m1.insert(pair<string, int>("BoneColor", 113));
			m1.insert(pair<string, int>("JointColor", 114));
			m1.insert(pair<string, int>("TendonColor", 115));
			m1.insert(pair<string, int>("MuscleColor", 116));
			m1.insert(pair<string, int>("ContractorColor", 117));
			m1.insert(pair<string, int>("LassoColor", 118));
			m1.insert(pair<string, int>("PEditSelect", 119));
			m1.insert(pair<string, int>("Strips2D", 120));
			m1.insert(pair<string, int>("FullScreen", 121));
			m1.insert(pair<string, int>("RadioStep", 122));
			m1.insert(pair<string, int>("RadioQuality", 123));
			m1.insert(pair<string, int>("RadioObjQuality", 124));
			m1.insert(pair<string, int>("RadioToneMapping", 125));
			m1.insert(pair<string, int>("RadioMinArea", 126));
			m1.insert(pair<string, int>("RadioMaxArea", 127));
			m1.insert(pair<string, int>("RadioMeshAccuracy", 128));
			m1.insert(pair<string, int>("RadioConverged", 129));
			m1.insert(pair<string, int>("RadioRenderEvery", 130));
			m1.insert(pair<string, int>("RadiosityOptions", 131));
			m1.insert(pair<string, int>("VolumeFogDensity", 132));
			m1.insert(pair<string, int>("VolumeSamples", 133));
			m1.insert(pair<string, int>("VolumeNoiseAmplitude", 134));
			m1.insert(pair<string, int>("VolumeNoiseScale", 135));
			m1.insert(pair<string, int>("VolumeNoiseGain", 136));
			m1.insert(pair<string, int>("VolumeSourceAtten", 137));
			m1.insert(pair<string, int>("VolumeSurfaceAtten", 138));
			m1.insert(pair<string, int>("VolumeVolumeAtten", 139));
			m1.insert(pair<string, int>("GlobalPanel", 140));
			m1.insert(pair<string, int>("D3DSetting", 141));
			m1.insert(pair<string, int>("D3DTranspLevel", 142));
			m1.insert(pair<string, int>("OpenGLSetting", 143));
			m1.insert(pair<string, int>("WdgEnSetting", 144));
			m1.insert(pair<string, int>("ToolTipsSetting", 145));
			m1.insert(pair<string, int>("AVIPlayerName", 146));
			m1.insert(pair<string, int>("PEditHighlight", 147));
			m1.insert(pair<string, int>("PathHTML", 148));
			m1.insert(pair<string, int>("CurveSegments", 149));
			m1.insert(pair<string, int>("RoundLineLongDiv", 150));
			m1.insert(pair<string, int>("RoundLineLatDiv", 151));
			m1.insert(pair<string, int>("RoundPlaneLongDiv", 152));
			m1.insert(pair<string, int>("RoundPlaneLatDiv", 153));
			m1.insert(pair<string, int>("SettingsX", 154));
			m1.insert(pair<string, int>("PrimitiveAddingType", 155));
			m1.insert(pair<string, int>("PGeosphereResolution", 156));
			m1.insert(pair<string, int>("PatchFacetizDetailDrag", 157));
			m1.insert(pair<string, int>("PatchFacetizDetailStatic", 158));
			m1.insert(pair<string, int>("PatchDisplay", 159));
			m1.insert(pair<string, int>("PatchHistRebuild", 160));
			m1.insert(pair<string, int>("CurveProjToler", 161));
			m1.insert(pair<string, int>("SnapDist", 162));
			m1.insert(pair<string, int>("SnapFlags", 163));
			m1.insert(pair<string, int>("SnapEdgeSegments", 164));
			m1.insert(pair<string, int>("PatchOptions", 165));
			m1.insert(pair<string, int>("ExtrudeSize", 166));
			m1.insert(pair<string, int>("GridObjectMove", 167));
			m1.insert(pair<string, int>("GridObjectRotate", 168));
			m1.insert(pair<string, int>("GridObjectScale", 169));
			m1.insert(pair<string, int>("GridEyeMove", 170));
			m1.insert(pair<string, int>("GridEyeRotate", 171));
			m1.insert(pair<string, int>("GridEyeScale", 172));
			m1.insert(pair<string, int>("GridXObjectMove", 173));
			m1.insert(pair<string, int>("GridXObjectRotate", 174));
			m1.insert(pair<string, int>("GridXObjectScale", 175));
			m1.insert(pair<string, int>("GridXEyeMove", 176));
			m1.insert(pair<string, int>("GridXEyeRotate", 177));
			m1.insert(pair<string, int>("GridXEyeScale", 178));
			m1.insert(pair<string, int>("GridYObjectMove", 179));
			m1.insert(pair<string, int>("GridYObjectRotate", 180));
			m1.insert(pair<string, int>("GridYObjectScale", 181));
			m1.insert(pair<string, int>("GridYEyeMove", 182));
			m1.insert(pair<string, int>("GridYEyeRotate", 183));
			m1.insert(pair<string, int>("GridYEyeScale", 184));
			m1.insert(pair<string, int>("GridZObjectMove", 185));
			m1.insert(pair<string, int>("GridZObjectRotate", 186));
			m1.insert(pair<string, int>("GridZObjectScale", 187));
			m1.insert(pair<string, int>("GridZEyeMove", 188));
			m1.insert(pair<string, int>("GridZEyeRotate", 189));
			m1.insert(pair<string, int>("GridZEyeScale", 190));
			m1.insert(pair<string, int>("OpenGL", 191));
			m1.insert(pair<string, int>("OglTranspLevel", 192));
			m1.insert(pair<string, int>("ActiveControlsMode", 193));
			m1.insert(pair<string, int>("ScreenRefreshIntSens", 194));
			m1.insert(pair<string, int>("NumBackupSceneFiles", 195));
			m1.insert(pair<string, int>("Selector", 196));
			m1.insert(pair<string, int>("LibPrim", 197));
			m1.insert(pair<string, int>("LibPrimPX", 198));
			m1.insert(pair<string, int>("LibPrimPY", 199));
			m1.insert(pair<string, int>("LibPrimSX", 200));
			m1.insert(pair<string, int>("LibPrimSY", 201));
			m1.insert(pair<string, int>("LibSupp", 202));
			m1.insert(pair<string, int>("LibSuppPX", 203));
			m1.insert(pair<string, int>("LibSuppPY", 204));
			m1.insert(pair<string, int>("LibSuppSX", 205));
			m1.insert(pair<string, int>("LibSuppSY", 206));
			m1.insert(pair<string, int>("LibShad1", 207));
			m1.insert(pair<string, int>("LibShad1PX", 208));
			m1.insert(pair<string, int>("LibShad1PY", 209));
			m1.insert(pair<string, int>("LibShad1SX", 210));
			m1.insert(pair<string, int>("LibShad1SY", 211));
			m1.insert(pair<string, int>("LibShad2", 212));
			m1.insert(pair<string, int>("LibShad2PX", 213));
			m1.insert(pair<string, int>("LibShad2PY", 214));
			m1.insert(pair<string, int>("LibShad2SX", 215));
			m1.insert(pair<string, int>("LibShad2SY", 216));
			m1.insert(pair<string, int>("LibShad3", 217));
			m1.insert(pair<string, int>("LibShad3PX", 218));
			m1.insert(pair<string, int>("LibShad3PY", 219));
			m1.insert(pair<string, int>("LibShad3SX", 220));
			m1.insert(pair<string, int>("LibShad3SY", 221));
			m1.insert(pair<string, int>("LibShad4", 222));
			m1.insert(pair<string, int>("LibShad4PX", 223));
			m1.insert(pair<string, int>("LibShad4PY", 224));
			m1.insert(pair<string, int>("LibShad4SX", 225));
			m1.insert(pair<string, int>("LibShad4SY", 226));
			m1.insert(pair<string, int>("GlObjExport", 227));
			m1.insert(pair<string, int>("GlObjImport", 228));
			m1.insert(pair<string, int>("GlObjScale", 229));
			m1.insert(pair<string, int>("GlObjFlags", 230));
			m1.insert(pair<string, int>("GlDXFFlags", 231));
			m1.insert(pair<string, int>("GDXFLayerName", 232));
			m1.insert(pair<string, int>("GDXFCurveSegs", 233));
			m1.insert(pair<string, int>("GDXF2dWidth", 234));
			m1.insert(pair<string, int>("GPSFilter", 235));
			m1.insert(pair<string, int>("GPSCurveRes", 236));
			m1.insert(pair<string, int>("GPSOStep", 237));
			m1.insert(pair<string, int>("GPSPStep", 238));
			m1.insert(pair<string, int>("GACISScale", 239));
			m1.insert(pair<string, int>("GACISFlags", 240));
			m1.insert(pair<string, int>("GDirXFlags", 241));
			m1.insert(pair<string, int>("Collision", 242));
			m1.insert(pair<string, int>("CollisionType", 243));
			m1.insert(pair<string, int>("ProjectsPath", 244));
			m1.insert(pair<string, int>("IBrowserSettings", 245));
			m1.insert(pair<string, int>("ArrayFlags", 246));
			m1.insert(pair<string, int>("RadArrayNumSegments", 247));
			m1.insert(pair<string, int>("RadArrayAngle", 248));
			m1.insert(pair<string, int>("RadArrayZOffset", 249));
			m1.insert(pair<string, int>("SplArrayNumSegments", 250));
			m1.insert(pair<string, int>("SplArrayOffset", 251));
			m1.insert(pair<string, int>("SceneLayersAdmin", 252));
			m1.insert(pair<string, int>("CurveConversionFlags", 253));
			m1.insert(pair<string, int>("AngleTreshold", 254));
			m1.insert(pair<string, int>("IconHelperX", 255));
			m1.insert(pair<string, int>("IconHelperY", 256));
			m1.insert(pair<string, int>("IconHelperWidth", 257));
			m1.insert(pair<string, int>("IconHelperHeight", 258));
			m1.insert(pair<string, int>("END", 259));

    	switch (m1[token]){

		case 1 :
            
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			
			break;
		case 11:
			
			break;
		case 12:
			
			break;
		case 13:
			
			break;
		case 14:
			
			break;
		case 15:
			
			break;
		case 16:
			
			break;
		case 17:
			
			break;
		case 18:
			
			break;
		case 19:
			
			break;
		case 20:
			
			break;
		case 21:
			
			break;
		case 22:
			
			break;
		case 23:
			
			break;
		case 24:
			
			break;
		case 25:
			
			break;
		case 26:
			
			break;
		case 27:
			
			break;
		case 28:
			
			break;
		case 29:
			
			break;
		case 30:
			
			break;
		case 31:
			
			break;
		case 32:
			
			break;
		case 33:
			
			break;
		case 34:
			
			break;
		case 35:
			
			break;
		case 36:
			
			break;
		case 37:
			
			break;
		case 38:
			
			break;
		case 39:
			
			break;
		case 40:
			
			break;
		case 41:
			
			break;
		case 42:
			
			break;
		case 43:
			
			break;
		case 44:
			
			break;
		case 45:
			
			break;
		case 46:
			
			break;
		case 47:
			
			break;
		case 48:
			
			break;
		case 49:
			
			break;
		case 50:
			
			break;
		case 51:
			
			break;
		case 52:
			
			break;
		case 53:
			
			break;
		case 54:
			
			break;
		case 55:
			
			break;
		case 56:
			
			break;
		case 57:
			
			break;
		case 58:
			
			break;
		case 59:
			
			break;
		case 60:
			
			break;
		case 61:
			
			break;
		case 62:
			
			break;
		case 63:
			
			break;
		case 64:
			
			break;
		case 65:
			
			break;
		case 66:
			
			break;
		case 67:
			
			break;
		case 68:
			
			break;
		case 69:
			
			break;
		case 70:
			
			break;
		case 71:
			
			break;
		case 72:
			
			break;
		case 73:
			
			break;
		case 74:
			
			break;
		case 75:
			
			break;
		case 76:
			
			break;
		case 77:
			
			break;
		case 78:
			
			break;
		case 79:
			
			break;
		case 80:
			
			break;
		case 81:
			
			break;
		case 82:
			
			break;
		case 83:
			
			break;
		case 84:
			
			break;
		case 85:
			
			break;
		case 86:
			
			break;
		case 87:
			
			break;
		case 88:
			
			break;
		case 89:
			
			break;
		case 90:
			
			break;
		case 91:
			
			break;
		case 92:
			
			break;
		case 93:
			
			break;
		case 94:
			
			break;
		case 95:
			
			break;
		case 96:
			
			break;
		case 97:
			
			break;
		case 98:
			
			break;
		case 99:
			
			break;
		case 100:
			
			break;
		case 101:
			
			break;
		case 102:
			
			break;
		case 103:
			
			break;
		case 104:
			
			break;
		case 105:
			
			break;
		case 106:
			
			break;
		case 107:
			
			break;
		case 108:
			
			break;
		case 109:
			
			break;
		case 110:
			
			break;
		case 111:
			
			break;
		case 112:
			
			break;
		case 113:
			
			break;
		case 114:
			
			break;
		case 115:
			
			break;
		case 116:
			
			break;
		case 117:
			
			break;
		case 118:
			
			break;
		case 119:
			
			break;
		case 120:
			
			break;
		case 121:
			
			break;
		case 122:
			
			break;
		case 123:
			
			break;
		case 124:
			
			break;
		case 125:
			
			break;
		case 126:
			
			break;
		case 127:
			
			break;
		case 128:
			
			break;
		case 129:
			
			break;
		case 130:
			
			break;
		case 131:
			
			break;
		case 132:
			
			break;
		case 133:
			
			break;
		case 134:
			
			break;
		case 135:
			
			break;
		case 136:
			
			break;
		case 137:
			
			break;
		case 138:
			
			break;
		case 139:
			
			break;
		case 140:
			
			break;
		case 141:
			
			break;
		case 142:
			
			break;
		case 143:
			
			break;
		case 144:
			
			break;
		case 145:
			
			break;
		case 146:
			
			break;
		case 147:
			
			break;
		case 148:
			
			break;
		case 149:
			
			break;
		case 150:
			
			break;
		case 151:
			
			break;
		case 152:
			
			break;
		case 153:
			
			break;
		case 154:
			
			break;
		case 155:
			
			break;
		case 156:
			
			break;
		case 157:
			
			break;
		case 158:
			
			break;
		case 159:
			
			break;
		case 160:
			
			break;
		case 161:
			
			break;
		case 162:
			
			break;
		case 163:
			
			break;
		case 164:
			
			break;
		case 165:
			
			break;
		case 166:
			
			break;
		case 167:
			
			break;
		case 168:
			
			break;
		case 169:
			
			break;
		case 170:
			
			break;
		case 171:
			
			break;
		case 172:
			
			break;
		case 173:
			
			break;
		case 174:
			
			break;
		case 175:
			
			break;
		case 176:
			
			break;
		case 177:
			
			break;
		case 178:
			
			break;
		case 179:
			
			break;
		case 180:
			
			break;
		case 181:
			
			break;
		case 182:
			
			break;
		case 183:
			
			break;
		case 184:
			
			break;
		case 185:
			
			break;
		case 186:
			
			break;
		case 187:
			
			break;
		case 188:
			
			break;
		case 189:
			
			break;
		case 190:
			
			break;
		case 191:
			
			break;
		case 192:
			
			break;
		case 193:
			
			break;
		case 194:
			
			break;
		case 195:
			
			break;
		case 196:
			
			break;
		case 197:
			
			break;
		case 198:
			
			break;
		case 199:
			
			break;
		case 200:
			
			break;
		case 201:
			
			break;
		case 202:
			
			break;
		case 203:
			
			break;
		case 204:
			
			break;
		case 205:
			
			break;
		case 206:
			
			break;
		case 207:
			
			break;
		case 208:
			
			break;
		case 209:
			
			break;
		case 210:
			
			break;
		case 211:
			
			break;
		case 212:
			
			break;
		case 213:
			
			break;
		case 214:
			
			break;
		case 215:
			
			break;
		case 216:
			
			break;
		case 217:
			
			break;
		case 218:
			
			break;
		case 219:
			
			break;
		case 220:
			
			break;
		case 221:
			
			break;
		case 222:
			
			break;
		case 223:
			
			break;
		case 224:
			
			break;
		case 225:
			
			break;
		case 226:
			
			break;
		case 227:
			
			break;
		case 228:
			
			break;
		case 229:
			
			break;
		case 230:
			
			break;
		case 231:
			
			break;
		case 232:
			
			break;
		case 233:
			
			break;
		case 234:
			
			break;
		case 235:
			
			break;
		case 236:
			
			break;
		case 237:
			
			break;
		case 238:
			
			break;
		case 239:
			
			break;
		case 240:
			
			break;
		case 241:
			
			break;
		case 242:
			
			break;
		case 243:
			
			break;
		case 244:
			
			break;
		case 245:
			
			break;
		case 246:
			
			break;
		case 247:
			
			break;
		case 248:
			
			break;
		case 249:
			
			break;
		case 250:
			
			break;
		case 251:
			
			break;
		case 252:
			
			break;
		case 253:
			
			break;
		case 254:
			
			break;
		case 255:
			
			break;
		case 256:
			
			break;
		case 257:
			
			break;
		case 258:
			
			break;
		case 259:
			
			break;

    	default:
			break;
    		cout << "nothing to see here" << endl;
    		break;
	    }
            if (token == "END"){
                break; //quits our loop
            }
        }
        cout << "Loaded Preferences" << endl;
        inputfile.close();
	}else{
	    cout << "No file specified, correct usage: ./preferences file.ini" << endl;
	}
}
