import 'package:atomic_sdk_flutter/atomic_session.dart';
import 'package:atomic_sdk_flutter/atomic_stream_container.dart';
import 'package:flutter/material.dart';
import 'package:flutter_boilerplate/my_session_delegate.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Atomic Boilerplate',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Atomic Boilerplate'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  AACStreamContainerConfiguration get configuration {
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

  @override
  Widget build(BuildContext context) {
    AACSession.initialise('<environmentId>', '<apiKey>');

    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Container(
                width: MediaQuery.of(context).size.width,
                height: MediaQuery.of(context).size.height,
                child: AACStreamContainer(
                  configuration: configuration,
                  containerId: '<containerId>',
                  sessionDelegate: MySessionDelegate(),
                )),
          ],
        ),
      ),
    );
  }
}

