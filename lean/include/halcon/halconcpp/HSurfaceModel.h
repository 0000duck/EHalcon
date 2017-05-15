/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 12.0
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSURFACEMODEL
#define HCPP_HSURFACEMODEL

namespace HalconCpp
{

// Represents an instance of a surface model.
class LIntExport HSurfaceModel : public HToolBase
{

public:

  // Create an uninitialized instance
  HSurfaceModel():HToolBase() {}

  // Copy constructor
  HSurfaceModel(const HSurfaceModel& source) : HToolBase(source) {}

  // Create HSurfaceModel from handle, taking ownership
  explicit HSurfaceModel(Hlong handle);

  // Set new handle, taking ownership
  void SetHandle(Hlong handle);

  // Deep copy of all data represented by this object instance
  HSurfaceModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_surface_model: Read a surface model from a file.
  explicit HSurfaceModel(const HString& FileName);

  // read_surface_model: Read a surface model from a file.
  explicit HSurfaceModel(const char* FileName);

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HTuple& GenParamName, const HTuple& GenParamValue);

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HString& GenParamName, const HString& GenParamValue);

  // create_surface_model: Create the data structure needed to perform surface-based matching.
  explicit HSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const char* GenParamName, const char* GenParamValue);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Free the memory of all surface models.
  static void ClearAllSurfaceModels();

  // Deserialize a surface model.
  void DeserializeSurfaceModel(const HSerializedItem& SerializedItemHandle);

  // Serialize a surface_model.
  HSerializedItem SerializeSurfaceModel() const;

  // Read a surface model from a file.
  void ReadSurfaceModel(const HString& FileName);

  // Read a surface model from a file.
  void ReadSurfaceModel(const char* FileName);

  // Write a surface model to a file.
  void WriteSurfaceModel(const HString& FileName) const;

  // Write a surface model to a file.
  void WriteSurfaceModel(const char* FileName) const;

  // Refine the pose of a surface model in a 3D scene.
  HPoseArray RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPoseArray& InitialPose, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Refine the pose of a surface model in a 3D scene.
  HPose RefineSurfaceModelPose(const HObjectModel3D& ObjectModel3D, const HPose& InitialPose, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene.
  HPoseArray FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, const HTuple& MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResultArray* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const HString& ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Find the best matches of a surface model in a 3D scene.
  HPose FindSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, double KeyPointFraction, double MinScore, const char* ReturnResultHandle, const HTuple& GenParamName, const HTuple& GenParamValue, HTuple* Score, HSurfaceMatchingResult* SurfaceMatchingResultID) const;

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const HTuple& ParamName) const;

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const HString& ParamName) const;

  // Return the parameters and properties of a surface model.
  HTuple GetSurfaceModelParam(const char* ParamName) const;

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const HString& GenParamName, const HString& GenParamValue);

  // Create the data structure needed to perform surface-based matching.
  void CreateSurfaceModel(const HObjectModel3D& ObjectModel3D, double RelSamplingDistance, const char* GenParamName, const char* GenParamValue);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HToolArrayRef;

typedef HToolArrayRef<HSurfaceModel> HSurfaceModelArrayRef;
typedef HSmartPtr< HSurfaceModelArrayRef > HSurfaceModelArrayPtr;


// Represents multiple tool instances
class LIntExport HSurfaceModelArray : public HToolArray
{

public:

  // Create empty array
  HSurfaceModelArray();

  // Create array from native array of tool instances
  HSurfaceModelArray(HSurfaceModel* classes, Hlong length);

  // Copy constructor
  HSurfaceModelArray(const HSurfaceModelArray &tool_array);

  // Destructor
  virtual ~HSurfaceModelArray();

  // Assignment operator
  HSurfaceModelArray &operator=(const HSurfaceModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HSurfaceModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HSurfaceModelArrayPtr *mArrayPtr;
};

}

#endif
