
import 'package:atomic_sdk_flutter/atomic_stream_container.dart';

class AtomicConfiguration{

  static String environmentId = "";
  static String apiKey = "";
  static String containerId= "";
  static String token= "";
  static String apiUrl = "";

  static AACStreamContainerConfiguration get configuration {
    AACStreamContainerConfiguration config = AACStreamContainerConfiguration();
    config.pollingInterval = 5;
    config.votingOption = AACVotingOption.both;
    config.interfaceStyle = AACInterfaceStyle.automatic;
    config.presentationStyle = AACPresentationStyle.withActionButton;
    config.enabledUiElements = AACUIElement.defaultValue;

    // Enable Card List Header
    config.enabledUiElements &= ~AACUIElement.cardListHeader;

    // Enable Card List Toast
    config.enabledUiElements &= ~AACUIElement.cardListToast;

    // Set Card List title
    config.setValueForCustomString(AACCustomString.cardListTitle, "");

    // Set Footer
    config.setValueForCustomString(AACCustomString.cardListFooterMessage, "");
    config.enabledUiElements |= AACUIElement.cardListFooterMessage;
    return config;
  }
}