// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Components/D3DCharacterAttributeComponent.h"

void FD3DGameplayAttribute::UpdateCurrentValue()
{
	float NewValue;

	if (Modifier.bUseOverride) {
		NewValue = Modifier.Override;
	}
	else {
		NewValue = Modifier.Multiply * (BaseValue * Modifier.Add);
	}

	SetCurrentValue(NewValue);
}

void FD3DGameplayAttribute::AddToBaseValue(float AdditiveValue)
{
	BaseValue += AdditiveValue;
}

void FD3DGameplayAttribute::ModifyToBaseValue(FD3DGameplayAttributeModifier NewModifier)
{
	float NewValue;

	if (Modifier.bUseOverride) {
		NewValue = NewModifier.Override;
	}
	else {
		NewValue = NewModifier.Multiply * (BaseValue * Modifier.Add);
	}

	SetBaseValue(NewValue);
}

void FD3DGameplayAttribute::SetModifier(FD3DGameplayAttributeModifier NewModifier)
{
	Modifier = NewModifier;
	//UpdateCurrentValue();
}

void FD3DGameplayAttribute::ClearModifier()
{
	Modifier = FD3DGameplayAttributeModifier::NullModifier();
	SetCurrentValue(BaseValue);

}
