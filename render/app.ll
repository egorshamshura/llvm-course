; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx12.0.0"

@px = global [131072 x i32] zeroinitializer, align 16
@__const.app.colors = private unnamed_addr constant [5 x i32] [i32 -40121, i32 -5963868, i32 -1736449, i32 -13312, i32 -7220481], align 16

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @dump() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %3

3:                                                ; preds = %24, %0
  %4 = load i32, ptr %1, align 4
  %5 = icmp ne i32 %4, 512
  br i1 %5, label %6, label %27

6:                                                ; preds = %3
  store i32 0, ptr %2, align 4
  br label %7

7:                                                ; preds = %20, %6
  %8 = load i32, ptr %2, align 4
  %9 = icmp ne i32 %8, 256
  br i1 %9, label %10, label %23

10:                                               ; preds = %7
  %11 = load i32, ptr %1, align 4
  %12 = load i32, ptr %2, align 4
  %13 = load i32, ptr %2, align 4
  %14 = mul nsw i32 %13, 512
  %15 = load i32, ptr %1, align 4
  %16 = add nsw i32 %14, %15
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [131072 x i32], ptr @px, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  call void @simPutPixel(i32 noundef %11, i32 noundef %12, i32 noundef %19)
  br label %20

20:                                               ; preds = %10
  %21 = load i32, ptr %2, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, ptr %2, align 4
  br label %7, !llvm.loop !5

23:                                               ; preds = %7
  br label %24

24:                                               ; preds = %23
  %25 = load i32, ptr %1, align 4
  %26 = add nsw i32 %25, 1
  store i32 %26, ptr %1, align 4
  br label %3, !llvm.loop !7

27:                                               ; preds = %3
  call void (...) @simFlush()
  ret void
}

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) #1

declare void @simFlush(...) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @left_right(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  store i32 0, ptr %3, align 4
  br label %5

5:                                                ; preds = %24, %1
  %6 = load i32, ptr %3, align 4
  %7 = icmp ne i32 %6, 512
  br i1 %7, label %8, label %27

8:                                                ; preds = %5
  store i32 0, ptr %4, align 4
  br label %9

9:                                                ; preds = %20, %8
  %10 = load i32, ptr %4, align 4
  %11 = icmp ne i32 %10, 256
  br i1 %11, label %12, label %23

12:                                               ; preds = %9
  %13 = load i32, ptr %2, align 4
  %14 = load i32, ptr %4, align 4
  %15 = mul nsw i32 %14, 512
  %16 = load i32, ptr %3, align 4
  %17 = add nsw i32 %15, %16
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [131072 x i32], ptr @px, i64 0, i64 %18
  store i32 %13, ptr %19, align 4
  br label %20

20:                                               ; preds = %12
  %21 = load i32, ptr %4, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, ptr %4, align 4
  br label %9, !llvm.loop !8

23:                                               ; preds = %9
  call void @dump()
  br label %24

24:                                               ; preds = %23
  %25 = load i32, ptr %3, align 4
  %26 = add nsw i32 %25, 1
  store i32 %26, ptr %3, align 4
  br label %5, !llvm.loop !9

27:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @right_left(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  store i32 511, ptr %3, align 4
  br label %5

5:                                                ; preds = %24, %1
  %6 = load i32, ptr %3, align 4
  %7 = icmp sgt i32 %6, 0
  br i1 %7, label %8, label %27

8:                                                ; preds = %5
  store i32 0, ptr %4, align 4
  br label %9

9:                                                ; preds = %20, %8
  %10 = load i32, ptr %4, align 4
  %11 = icmp ne i32 %10, 256
  br i1 %11, label %12, label %23

12:                                               ; preds = %9
  %13 = load i32, ptr %2, align 4
  %14 = load i32, ptr %4, align 4
  %15 = mul nsw i32 %14, 512
  %16 = load i32, ptr %3, align 4
  %17 = add nsw i32 %15, %16
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [131072 x i32], ptr @px, i64 0, i64 %18
  store i32 %13, ptr %19, align 4
  br label %20

20:                                               ; preds = %12
  %21 = load i32, ptr %4, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, ptr %4, align 4
  br label %9, !llvm.loop !10

23:                                               ; preds = %9
  call void @dump()
  br label %24

24:                                               ; preds = %23
  %25 = load i32, ptr %3, align 4
  %26 = add nsw i32 %25, -1
  store i32 %26, ptr %3, align 4
  br label %5, !llvm.loop !11

27:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @up_down(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  store i32 0, ptr %3, align 4
  br label %5

5:                                                ; preds = %24, %1
  %6 = load i32, ptr %3, align 4
  %7 = icmp ne i32 %6, 256
  br i1 %7, label %8, label %27

8:                                                ; preds = %5
  store i32 0, ptr %4, align 4
  br label %9

9:                                                ; preds = %20, %8
  %10 = load i32, ptr %4, align 4
  %11 = icmp ne i32 %10, 512
  br i1 %11, label %12, label %23

12:                                               ; preds = %9
  %13 = load i32, ptr %2, align 4
  %14 = load i32, ptr %3, align 4
  %15 = mul nsw i32 %14, 512
  %16 = load i32, ptr %4, align 4
  %17 = add nsw i32 %15, %16
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [131072 x i32], ptr @px, i64 0, i64 %18
  store i32 %13, ptr %19, align 4
  br label %20

20:                                               ; preds = %12
  %21 = load i32, ptr %4, align 4
  %22 = add nsw i32 %21, 1
  store i32 %22, ptr %4, align 4
  br label %9, !llvm.loop !12

23:                                               ; preds = %9
  call void @dump()
  br label %24

24:                                               ; preds = %23
  %25 = load i32, ptr %3, align 4
  %26 = add nsw i32 %25, 1
  store i32 %26, ptr %3, align 4
  br label %5, !llvm.loop !13

27:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @down_up(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  store i32 0, ptr %3, align 4
  br label %5

5:                                                ; preds = %24, %1
  %6 = load i32, ptr %3, align 4
  %7 = icmp ne i32 %6, 256
  br i1 %7, label %8, label %27

8:                                                ; preds = %5
  store i32 511, ptr %4, align 4
  br label %9

9:                                                ; preds = %20, %8
  %10 = load i32, ptr %4, align 4
  %11 = icmp sgt i32 %10, 0
  br i1 %11, label %12, label %23

12:                                               ; preds = %9
  %13 = load i32, ptr %2, align 4
  %14 = load i32, ptr %3, align 4
  %15 = mul nsw i32 %14, 512
  %16 = load i32, ptr %4, align 4
  %17 = add nsw i32 %15, %16
  %18 = sext i32 %17 to i64
  %19 = getelementptr inbounds [131072 x i32], ptr @px, i64 0, i64 %18
  store i32 %13, ptr %19, align 4
  br label %20

20:                                               ; preds = %12
  %21 = load i32, ptr %4, align 4
  %22 = add nsw i32 %21, -1
  store i32 %22, ptr %4, align 4
  br label %9, !llvm.loop !14

23:                                               ; preds = %9
  call void @dump()
  br label %24

24:                                               ; preds = %23
  %25 = load i32, ptr %3, align 4
  %26 = add nsw i32 %25, 1
  store i32 %26, ptr %3, align 4
  br label %5, !llvm.loop !15

27:                                               ; preds = %5
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define void @app() #0 {
  %1 = alloca [5 x i32], align 16
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %1, ptr align 16 @__const.app.colors, i64 20, i1 false)
  br label %4

4:                                                ; preds = %0, %31
  %5 = call i32 (...) @simRand()
  %6 = urem i32 %5, 5
  %7 = zext i32 %6 to i64
  %8 = getelementptr inbounds [5 x i32], ptr %1, i64 0, i64 %7
  %9 = load i32, ptr %8, align 4
  store i32 %9, ptr %2, align 4
  %10 = call i32 (...) @simRand()
  %11 = urem i32 %10, 4
  store i32 %11, ptr %3, align 4
  %12 = load i32, ptr %3, align 4
  %13 = icmp eq i32 %12, 0
  br i1 %13, label %14, label %16

14:                                               ; preds = %4
  %15 = load i32, ptr %2, align 4
  call void @left_right(i32 noundef %15)
  br label %16

16:                                               ; preds = %14, %4
  %17 = load i32, ptr %3, align 4
  %18 = icmp eq i32 %17, 1
  br i1 %18, label %19, label %21

19:                                               ; preds = %16
  %20 = load i32, ptr %2, align 4
  call void @right_left(i32 noundef %20)
  br label %21

21:                                               ; preds = %19, %16
  %22 = load i32, ptr %3, align 4
  %23 = icmp eq i32 %22, 2
  br i1 %23, label %24, label %26

24:                                               ; preds = %21
  %25 = load i32, ptr %2, align 4
  call void @up_down(i32 noundef %25)
  br label %26

26:                                               ; preds = %24, %21
  %27 = load i32, ptr %3, align 4
  %28 = icmp eq i32 %27, 3
  br i1 %28, label %29, label %31

29:                                               ; preds = %26
  %30 = load i32, ptr %2, align 4
  call void @down_up(i32 noundef %30)
  br label %31

31:                                               ; preds = %29, %26
  br label %4
}

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #2

declare i32 @simRand(...) #1

attributes #0 = { noinline nounwind optnone ssp uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cmov,+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cmov,+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #2 = { nocallback nofree nounwind willreturn memory(argmem: readwrite) }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 7, !"frame-pointer", i32 2}
!4 = !{!"Homebrew clang version 17.0.6"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
!10 = distinct !{!10, !6}
!11 = distinct !{!11, !6}
!12 = distinct !{!12, !6}
!13 = distinct !{!13, !6}
!14 = distinct !{!14, !6}
!15 = distinct !{!15, !6}
