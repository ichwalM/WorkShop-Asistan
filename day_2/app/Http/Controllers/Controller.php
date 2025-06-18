<?php

namespace App\Http\Controllers;

abstract class Controller
{
    public function ApiResponse($message, $data=NULL, $statusCode = 200)
    {
        return response()->json([
            'message' => $message,
            'data' => $data,
        ], $statusCode);
    }
}
