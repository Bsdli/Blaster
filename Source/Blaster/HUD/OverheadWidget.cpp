#include "OverheadWidget.h"
#include "Components/TextBlock.h"

//设置头顶文字
void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
		DisplayText->SetText(FText::FromString(TextToDisplay));
}

//获取并显示角色类型
void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();//获取角色类型
	FString Role;
	switch (RemoteRole)
	{
		case ENetRole::ROLE_Authority:
			Role = FString("Authority");
			break;
		case ENetRole::ROLE_AutonomousProxy:
			Role = FString("Autonomous Proxy");
			break;
		case ENetRole::ROLE_SimulatedProxy:
			Role = FString("Simulated Proxy");
			break;
		case ENetRole::ROLE_None:
			Role = FString("None");
			break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *Role);
	SetDisplayText(RemoteRoleString);
}

//离开主关卡时删除头顶显示
void UOverheadWidget::NativeDestruct()
{
	Super::NativeDestruct();
	RemoveFromParent();
}