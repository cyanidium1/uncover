
#include "JWAN_LayerBlendingLogic.h"
#include "AnimationRuntime.h"
#include "Animation/AnimTrace.h"
#include "UObject/ObjectMacros.h"
#include "Animation/AnimNode_Inertialization.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/Skeleton.h"

#define DEFAULT_SOURCEINDEX 0xFF

void FJWAN_LayerBlendingLogic::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
    //Funkcja inicjuj¹ca noda
    AnimInst = Cast<UAnimInstance>(Context.AnimInstanceProxy->GetAnimInstanceObject());
    BaseLayerInput.Initialize(Context);
    OverlayLayerInput.Initialize(Context);
    BasePosesInput.Initialize(Context);

}

void FJWAN_LayerBlendingLogic::CacheBones_AnyThread(const FAnimationCacheBonesContext& Context)
{
    //Funkcja inicjuj¹ca noda
    DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(CacheBones_AnyThread)
    BaseLayerInput.CacheBones(Context);
    OverlayLayerInput.CacheBones(Context);
    BasePosesInput.CacheBones(Context);

}

void FJWAN_LayerBlendingLogic::Update_AnyThread(const FAnimationUpdateContext& Context)
{
    //Funkcja aktualizowana z ka¿d¹ klatk¹
    DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Update_AnyThread)
    GetEvaluateGraphExposedInputs().Execute(Context);
    BaseLayerInput.Update(Context);
    OverlayLayerInput.Update(Context);
    BasePosesInput.Update(Context);
}

void FJWAN_LayerBlendingLogic::Evaluate_AnyThread(FPoseContext& Output)
{
    //Funkcja aktualizowana z ka¿d¹ klatk¹
    DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(Evaluate_AnyThread)
    ANIM_MT_SCOPE_CYCLE_COUNTER(BlendPosesInGraph, !IsInGameThread());
    //Init Inputs
    FPoseContext PoseBase(Output);
    FPoseContext PoseOverlay(Output);
    FPoseContext PoseDef(Output);
    BaseLayerInput.Evaluate(PoseBase);
    OverlayLayerInput.Evaluate(PoseOverlay);
    BasePosesInput.Evaluate(PoseDef);


}

void FJWAN_LayerBlendingLogic::GatherDebugData(FNodeDebugData& DebugData)
{
    FString DebugLine = DebugData.GetNodeName(this);


    DebugData.AddDebugItem(DebugLine);

    BaseLayerInput.GatherDebugData(DebugData);
}

void FJWAN_LayerBlendingLogic::BlendTwoPosesContext(FPoseContext& PoseA, FPoseContext& PoseB, float Alpha, FPoseContext& OP)
{
    return;
}

//MAKE ADDITIVE POSE FROM TWO ANIMATIONS
void FJWAN_LayerBlendingLogic::MakeAdditiveContext(FPoseContext& Base, FPoseContext& Add, bool MeshSpace, FPoseContext& OP)
{
    return;
}

//LAYER BLENDING SINGLE - EVALUATE
void FJWAN_LayerBlendingLogic::ApplyAdditiveWithSlotEvaluate(FPoseContext& OP, FPoseContext& LBase, FPoseContext& LOverlay, FPoseContext& LAdditive, 
    float AddAlpha, float BlendAlpha, FName AnimSlotName, FSlotNodeWeightInfo SlotWeight, bool UseMeshSpace)
{
    return;
}

//LAYER BLENDING SINGLE - UPDATE
void FJWAN_LayerBlendingLogic::ApplyAdditiveWithSlotUpdate(FPoseContext& LBase, FPoseContext& LOverlay, FPoseContext& LAdditive, 
    float AddAlpha, float BlendAlpha, FName AnimSlotName)
{
    return;
}

void FJWAN_LayerBlendingLogic::BlendPerBoneEvaluate(FPoseContext& OP, FPoseContext& PoseA, FPoseContext& PoseB, bool UseMeshSpaceRotation, bool UseMeshSpaceScaleBlend, 
    TArray<FPerBoneBlendWeight> CurrentBoneBlendW, TArray<uint8> CurvePoseSourceI, bool UseBlendByWeight, float BlendAlpha)
{
    return;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Simple Curve Value From Anim Inst
float FJWAN_LayerBlendingLogic::CurveValue(FName CurveName)
{
    //return 1.0;
    if(IsValid(AnimInst)==true)
    {
        return FMath::Clamp<float>(AnimInst->GetCurveValue(CurveName),0.0,1.0);
    }
    return 0.0f;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ||| L A Y E R   B L E N D   P E R   B O N E |||
void FJWAN_LayerBlendingLogic::UpdateMaskWeightsValue(const FAnimationUpdateContext& C, TArray<FPerBoneBlendWeight>& DBBW, TArray<FPerBoneBlendWeight> CBBW, 
    TArray<float> BlendWeightsPerPose, bool BlendRootMotionBasedOnRoot, FGuid& InSkelGuid, FGuid& InVirtualBonesGuid, uint16& RBSN, TArray<uint8>& CPSI, 
    TArray<FInputBlendPose> InLayerSetup, float BlendAlpha)
{
    return;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ||| L A Y E R   B L E N D   P E R   B O N E |||  Rebuild cache per bone blend weights from the skeleton
void FJWAN_LayerBlendingLogic::RebuildPerBoneBlendWeights(const USkeleton* InSkeleton, TArray<FPerBoneBlendWeight>& PBBW, TArray<FInputBlendPose> InLayerSetup, FGuid& InSkelGuid, FGuid& InVirtualBonesGuid)
{
    return;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ||| L A Y E R   B L E N D   P E R   B O N E |||  Check whether per-bone blend weights are valid according to the skeleton (GUID check)
bool FJWAN_LayerBlendingLogic::ArePerBoneBlendWeightsValid(const USkeleton* InSkeleton, FGuid& InSkelGuid, FGuid& InVirtualBonesGuid)
{
    return (InSkeleton != nullptr && InSkeleton->GetGuid() == InSkelGuid && InSkeleton->GetVirtualBoneGuid() == InVirtualBonesGuid);
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ||| L A Y E R   B L E N D   P E R   B O N E |||  Update Cached Bone Data
void FJWAN_LayerBlendingLogic::UpdateCachedBoneData(const FBoneContainer& RequiredBones, const USkeleton* Skeleton, TArray<FPerBoneBlendWeight>& CurrentBoneBlendOutput, FGuid& InSkelGuid,
    FGuid& InVirtualBonesGuid, uint16& RBSN, TArray<uint8>& CPSI, TArray<FInputBlendPose> InLayerSetup, float BlendAlpha)
{
    return;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ||| L A Y E R   B L E N D   P E R   B O N E ||| MACRO - CREATE LayerBlend Mask
TArray<FInputBlendPose> FJWAN_LayerBlendingLogic::CreateLayerBlendValue(TArray<FName> BonesName, TArray<int> BlendDepth)
{
    TArray<FInputBlendPose> LBP = {};
    FInputBlendPose AddBlendPose;
    FBranchFilter AddFilter;
    int ii = -1;
    if (BonesName.Num() > 0 && BlendDepth.Num() > 0)
    {
        for (FName& CurrentName : BonesName)
        {
            ii = ii + 1;
            AddFilter.BoneName = CurrentName;
            if (BlendDepth.IsValidIndex(ii) == true)
            { AddFilter.BlendDepth = BlendDepth[ii]; }
            else
            { AddFilter.BlendDepth = 0; }
            AddBlendPose.BranchFilters.Add(AddFilter);
        }
        LBP.Add(AddBlendPose);
        return LBP;
    }
    return LBP;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//SLOT UPDATE
void FJWAN_LayerBlendingLogic::SlotUpdate(const FAnimationUpdateContext& Context, FName SName, FPoseLink InputPose, FSlotNodeWeightInfo Weight)
{
    return;
}

