// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "D3DCharacterAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FD3DGameplayAttributeCurrentValueChangedSignature, float, NewValue, float, PreviousValue, float, BaseValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FD3DGameplayAttributeBaseValueChangedSignature, float, NewValue, float, PreviousValue, float, CurrentValue);

USTRUCT(BlueprintType)
struct FD3DGameplayAttributeModifier {

	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes")
	float Add = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes")
	float Multiply = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bUseOverride = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes", meta = (EditCondition = "bUseOverride"))
	float Override = 0.0f;

	FD3DGameplayAttributeModifier Combine(FD3DGameplayAttributeModifier other) const
	{
		other.Add += Add;
		other.Multiply *= Multiply;
		other.bUseOverride = bUseOverride;
		other.Override = Override;
		return other;
	}

	static FD3DGameplayAttributeModifier NullModifier() {
		return FD3DGameplayAttributeModifier();
	}

	static FD3DGameplayAttributeModifier OverrideModifier(float NewValue) {
		return FD3DGameplayAttributeModifier(0.0f, 1.0f, true, NewValue);
	}
};



USTRUCT(BlueprintType)
struct FD3DGameplayAttribute {

	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FD3DGameplayAttributeCurrentValueChangedSignature OnCurrentValueChanged;
	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FD3DGameplayAttributeCurrentValueChangedSignature OnBaseValueChanged;

	FD3DGameplayAttribute() : CurrentValue(0.0f), BaseValue(0.0f) {
	}

	FD3DGameplayAttribute(float defaultValue) : BaseValue(defaultValue){
		UpdateCurrentValue();
	}

	float GetCurrentValue() const { return CurrentValue; }
	void SetCurrentValue(float newValue)
	{
		float PreviousValue = CurrentValue;
		CurrentValue = newValue;
		if (!FMath::IsNearlyEqual(CurrentValue, PreviousValue)) {
			OnCurrentValueChanged.Broadcast(CurrentValue, PreviousValue, BaseValue);
		}
	}
	void UpdateCurrentValue();

	float GetBaseValue() const { return BaseValue; }
	void SetBaseValue(float newValue)
	{
		float PreviousValue = BaseValue;
		BaseValue = newValue;
		if (!FMath::IsNearlyEqual(BaseValue, PreviousValue)) {
			OnBaseValueChanged.Broadcast(BaseValue, PreviousValue, CurrentValue);
		}
	}

	
	void AddToBaseValue(float AdditiveValue);
	void ModifyToBaseValue(FD3DGameplayAttributeModifier NewModifier);

	void SetModifier(FD3DGameplayAttributeModifier NewModifier);
	void ClearModifier();


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float CurrentValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float BaseValue;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FD3DGameplayAttributeModifier Modifier = FD3DGameplayAttributeModifier::NullModifier();
};

UCLASS()
class UD3DGameplayAttributesLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void SetCurrentValue(UPARAM(ref)FD3DGameplayAttribute& Attribute, float newValue)
	{
		Attribute.SetCurrentValue(newValue);
	}

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void SetBaseValue(UPARAM(ref)FD3DGameplayAttribute& Attribute, float newValue)
	{
		Attribute.SetCurrentValue(newValue);
	}

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	static void SetModifier(UPARAM(ref)FD3DGameplayAttribute& Attribute, FD3DGameplayAttributeModifier NewModifier)
	{
		Attribute.SetModifier(NewModifier);
	}


};

/**
 * 
 */
UCLASS()
class PROTOTYPEBP_API UD3DCharacterAttributeComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FD3DGameplayAttribute Health{ 100 };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	FD3DGameplayAttribute MaxHealth{ 100 };

protected:

	float health = 100;

};
