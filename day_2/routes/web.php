<?php

use App\Http\Controllers\BookController;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});
Route::get('book', [BookController::class,'index']);
Route::get('kirim-email',[BookController::class, 'sendEmail']);