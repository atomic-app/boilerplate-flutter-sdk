import 'package:flutter/material.dart';
import 'package:atomic_sdk_flutter/atomic_stream_container.dart';
import 'package:atomic_sdk_flutter/atomic_card_runtime_variable.dart';
import 'package:atomic_sdk_flutter/atomic_card_event.dart';

class MySessionDelegate  extends AACSessionDelegate {

  @override
  Future<String> authToken() {
    return Future.value("");
  }


}