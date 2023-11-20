import 'package:atomic_sdk_flutter/atomic_stream_container.dart';

class AtomicConfiguration {
  static String environmentId = '';
  static String apiKey = '';
  static String containerId = '';
  static String token = '';
  static String apiUrl = '';

  static AACStreamContainerConfiguration get configuration {
    final config = AACStreamContainerConfiguration()
      ..pollingInterval = 5
      ..votingOption = AACVotingOption.both
      ..interfaceStyle = AACInterfaceStyle.automatic
      ..presentationStyle = AACPresentationStyle.withActionButton
      ..enabledUiElements = AACUIElement.defaultValue
      // Set Card List title
      ..setValueForCustomString(AACCustomString.cardListTitle, '')
      // Set Footer
      ..setValueForCustomString(AACCustomString.cardListFooterMessage, '')
      ..enabledUiElements |= AACUIElement.cardListFooterMessage;

    // Disables Card List Header
    //config.enabledUiElements &= ~AACUIElement.cardListHeader;

    // Disables Card List Toast
    //config.enabledUiElements &= ~AACUIElement.cardListToast;

    return config;
  }
}
